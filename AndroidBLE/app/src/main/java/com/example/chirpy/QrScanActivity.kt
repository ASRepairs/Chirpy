package com.example.chirpy

import android.app.Activity
import android.content.Intent
import android.os.Bundle
import com.google.zxing.integration.android.IntentIntegrator
import com.journeyapps.barcodescanner.CaptureActivity
class PortraitCaptureActivity : CaptureActivity()
class QrScanActivity : Activity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Launch ZXing integrated scanner
        IntentIntegrator(this).apply {
            setDesiredBarcodeFormats(IntentIntegrator.QR_CODE)
            setPrompt("Scan QR code to connect")
            setBeepEnabled(false)
            setOrientationLocked(true)
            setCaptureActivity(PortraitCaptureActivity::class.java)
            initiateScan()
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        val result = IntentIntegrator.parseActivityResult(requestCode, resultCode, data)
        if (result != null && result.contents != null) {
            // Pass scanned result back to MainActivity
            val returnIntent = Intent().apply {
                putExtra("SCAN_RESULT", result.contents)
            }
            setResult(RESULT_OK, returnIntent)
        } else {
            setResult(RESULT_CANCELED)
        }
        finish()
    }
}
