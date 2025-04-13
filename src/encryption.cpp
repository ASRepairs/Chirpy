//
// Created by ASRepairs on 4/13/2025.
//

#include "encryption.h"
#include "mbedtls/aes.h"
#include "mbedtls/base64.h"
#include <string>
#include <vector>
#include <Arduino.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_system.h"

static const char *TAG_ENC = "AES_ENCRYPTION";


/**
 * PKCS#7 pad: we compute how many bytes are needed to round
 * up to the nearest multiple of AES block size (16). We append
 * that many bytes at the end, each set to the pad length.
 */
static size_t pkcs7Pad(uint8_t* buffer, size_t dataLen, size_t blockSize)
{
    size_t paddingLen = blockSize - (dataLen % blockSize);
    for (size_t i = 0; i < paddingLen; i++) {
        buffer[dataLen + i] = (uint8_t)paddingLen;
    }
    return dataLen + paddingLen;
}

/*
 * PKCS#7 unpad: read the last byte to see how many bytes to remove.
 */
static bool pkcs7Unpad(uint8_t* buffer, size_t &dataLen, size_t blockSize)
{
    if (dataLen == 0) {
        return false;
    }
    uint8_t padVal = buffer[dataLen - 1];
    if (padVal == 0 || padVal > blockSize) {
        // invalid padding
        return false;
    }
    // further validation is possible, but let's keep it simple
    dataLen -= padVal;
    return true;
}

//the decrypt function //TODO: real implementation
/*
 * decryptAES256Raw:
 *   Input is [ IV(16 bytes) + ciphertext ] in binary form.
 */
bool decryptAES256(const uint8_t* cipherData, size_t cipherLen,
                      const unsigned char* key, size_t keyLen,
                      uint8_t* outPlain, size_t &outPlainLen)
{
    // should be at least 16 for IV
    if (cipherLen < 16) {
        ESP_LOGE(TAG_ENC, "cipherLen too short, no IV found");
        return false;
    }

    //do the decryption in a local buffer so we can remove PKCS#7 padding easily.
    const size_t MAX_DATA = 1024; //TODO: adjust later
    if (cipherLen - 16 > MAX_DATA) {
        ESP_LOGE(TAG_ENC, "ciphertext too large");
        return false;
    }

    static uint8_t tempBuf[MAX_DATA + 16]; // for block alignment

    // Extract IV
    uint8_t iv[16];
    memcpy(iv, cipherData, 16);

    // The rest is ciphertext
    size_t encLen = cipherLen - 16;
    memcpy(tempBuf, cipherData + 16, encLen);

    // the AES
    mbedtls_aes_context aes;
    mbedtls_aes_init(&aes);
    int ret = mbedtls_aes_setkey_dec(&aes, key, keyLen * 8);
    if (ret != 0) {
        mbedtls_aes_free(&aes);
        ESP_LOGE(TAG_ENC, "AES setkey_dec failed");
        return false;
    }

    // Decrypt in place
    ret = mbedtls_aes_crypt_cbc(&aes,
                                MBEDTLS_AES_DECRYPT,
                                encLen,
                                iv,
                                tempBuf,
                                tempBuf);
    mbedtls_aes_free(&aes);

    if (ret != 0) {
        ESP_LOGE(TAG_ENC, "AES decryption failed");
        return false;
    }

    // Remove PKCS#7 padding
    size_t plainLen = encLen;
    if (!pkcs7Unpad(tempBuf, plainLen, 16)) {
        ESP_LOGE(TAG_ENC, "Invalid PKCS#7 padding");
        return false;
    }

    if (plainLen > outPlainLen) {
        ESP_LOGE(TAG_ENC, "outPlain buffer too small");
        return false;
    }

    // Copy to output
    memcpy(outPlain, tempBuf, plainLen);
    outPlainLen = plainLen;
    return true;
}

bool encryptAES256(const uint8_t* plaintext, size_t plaintextLen,
                      const unsigned char* key, size_t keyLen,
                      uint8_t* outCipher, size_t &outCipherLen)
{
    // We need enough space: IV(16) + padded plaintext.
    // just a demo, define a max message size
    const size_t MAX_DATA = 1024;  //TODO: adjust later
    if (plaintextLen > MAX_DATA) {
        ESP_LOGE(TAG_ENC, "plaintext too large");
        return false;
    }
    // everything in a local buffer
    static uint8_t tempBuf[MAX_DATA + 16]; // +16 for padding overhead
    memcpy(tempBuf, plaintext, plaintextLen);

    // PKCS#7 pad in place
    size_t blockSize = 16;
    size_t paddedLen = pkcs7Pad(tempBuf, plaintextLen, blockSize);

    // random IV
    uint8_t iv[16];
    esp_fill_random(iv, sizeof(iv));

    // the AES
    mbedtls_aes_context aes;
    mbedtls_aes_init(&aes);
    int ret = mbedtls_aes_setkey_enc(&aes, key, keyLen * 8);
    if (ret != 0) {
        mbedtls_aes_free(&aes);
        ESP_LOGE(TAG_ENC, "AES setkey_enc failed");
        return false;
    }

    // Encrypt in CBC mode, in place
    ret = mbedtls_aes_crypt_cbc(&aes,
                                MBEDTLS_AES_ENCRYPT,
                                paddedLen,
                                iv,
                                tempBuf,       // in
                                tempBuf);      // out (in place)
    mbedtls_aes_free(&aes);

    if (ret != 0) {
        ESP_LOGE(TAG_ENC, "AES encryption failed");
        return false;
    }

    // Now tempBuf holds the ciphertext of length paddedLen.
    // We output: [IV(16) + ciphertext(paddedLen)]
    size_t totalLen = 16 + paddedLen;
    if (totalLen > outCipherLen) {
        ESP_LOGE(TAG_ENC, "outCipher buffer too small");
        return false;
    }

    // add IV to outCipher
    memcpy(outCipher, iv, 16);
    // add ciphertext
    memcpy(outCipher + 16, tempBuf, paddedLen);

    // The function caller can see how many bytes are used
    outCipherLen = totalLen;
    return true;
}

// Return pointer to the 32-byte key for a given group string (e.g. "gr1", "gr2")
const unsigned char* getKeyForGroup(const String &groupId)
{
    auto it = groupKeyMap.find(groupId);
    if (it == groupKeyMap.end()) {
        Serial.printf("Group ID '%s' not found, defaulting to 'gr1'\n", groupId.c_str());
        return groupKeyMap["gr1"].data();
    }
    return it->second.data();
}