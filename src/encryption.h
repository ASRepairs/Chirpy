//
// Created by user on 4/13/2025.
//
#pragma once
#include <Arduino.h>
#include <map>
#include <array>
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

// Return pointer to the 32-byte key for a given group string
const unsigned char* getKeyForGroup(const String &groupId);

/**
 * Encrypt a plaintext buffer with AES-256-CBC, skipping Base64.
 *
 *  - plaintext      : pointer to input data
 *  - plaintextLen   : length of input data in bytes
 *  - key            : pointer to 32-byte (256-bit) key
 *  - outCipher      : output buffer where we write [ IV(16 bytes) + ciphertext ]
 *  - outCipherLen   : (in/out) on input, the max capacity of outCipher. On output, the number of bytes actually used.
 *
 * Return true on success, false on error.
 *
 * NOTE:
 *  - We do in-place PKCS#7 padding in a small temporary buffer.
 *  - The final output (IV + ciphertext) is placed in 'outCipher'.
 *  - If you want to do bigger messages, increase the buffer limit or make it dynamic.
 */
bool encryptAES256(const uint8_t* plaintext, size_t plaintextLen,
                      const unsigned char* key, size_t keyLen,
                      uint8_t* outCipher, size_t &outCipherLen);

/**
 * Decrypt a binary buffer that contains [ IV(16 bytes) + ciphertext ],
 * skipping Base64. We remove PKCS#7 padding to produce the plaintext.
 *
 *  - cipherData     : pointer to [ IV + ciphertext ]
 *  - cipherLen      : total length of that buffer
 *  - key            : pointer to 32-byte (256-bit) key
 *  - outPlain       : output buffer for the decrypted plaintext
 *  - outPlainLen    : (in/out) on input: capacity of outPlain; on output: actual plaintext length
 *
 * Return true on success, false on error.
 */
bool decryptAES256(const uint8_t* cipherData, size_t cipherLen,
                      const unsigned char* key, size_t keyLen,
                      uint8_t* outPlain, size_t &outPlainLen);

static std::map<String, std::array<unsigned char, 32>> groupKeyMap = { //TODO: really unsecure but should be ok for group demo. in real production this should be changed to public and private instead
    {
        "gr1",
        { 0x10, 0xC3, 0xA4, 0x6F, 0x2B, 0x8D, 0x64, 0x5E,
          0x91, 0x32, 0x40, 0xF9, 0x01, 0xAA, 0x83, 0x45,
          0x37, 0x54, 0x2A, 0xEE, 0xDC, 0xC5, 0x67, 0x59,
          0x7A, 0x27, 0x85, 0x73, 0xA1, 0xB9, 0xC0, 0x2F }
    },
    {
        "gr2",
        { 0x55, 0xEE, 0x20, 0x11, 0xDF, 0xA3, 0x76, 0x42,
          0x2F, 0x0A, 0x9B, 0xCC, 0x19, 0x99, 0x11, 0x88,
          0xA0, 0x00, 0xF1, 0xBD, 0x67, 0x12, 0x6B, 0x88,
          0xCD, 0xEF, 0x44, 0x99, 0x77, 0x66, 0x23, 0x10 }
    },
    {
        "gr3",
        { 0x99, 0x54, 0x66, 0x08, 0xFF, 0x03, 0x22, 0x89,
          0x11, 0x0B, 0xC4, 0xDA, 0x9F, 0x88, 0x76, 0x52,
          0x12, 0xBE, 0x33, 0x70, 0x41, 0xAB, 0x3C, 0xCE,
          0xFE, 0x97, 0x77, 0xD1, 0x78, 0xC8, 0xDE, 0x6A }
    },
    {
        "gr4",
        { 0x17, 0xD5, 0xA2, 0xAA, 0xEB, 0xC2, 0xDF, 0x37,
          0x44, 0x15, 0x2F, 0x60, 0x33, 0xAB, 0x60, 0x51,
          0xC4, 0x88, 0x55, 0x11, 0x91, 0x7F, 0x0E, 0x39,
          0x3B, 0x22, 0x16, 0x75, 0xC9, 0x99, 0x81, 0xAA }
    }
};
#endif //ENCRYPTION_H
