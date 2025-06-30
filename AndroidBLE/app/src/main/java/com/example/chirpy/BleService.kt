package com.example.chirpy

import android.app.NotificationChannel
import android.app.NotificationManager
import android.bluetooth.BluetoothGatt
import android.os.Build
import androidx.core.app.NotificationCompat
import androidx.lifecycle.LifecycleService

class BleService : LifecycleService() {

    companion object {
        const val CHANNEL_ID = "ble_foreground"
        const val NOTIF_ID   = 42
    }

    private var gatt: BluetoothGatt? = null

    override fun onCreate() {
        super.onCreate()
        createChannelIfNeeded()

        // Mandatory: start in the foreground within 10 s
        val notif = NotificationCompat.Builder(this, CHANNEL_ID)
            .setSmallIcon(R.drawable.ic_stat_name)
            .setContentTitle("Chirpy is connected")
            .setContentText("Keeping your watch link alive")
            .build()
        startForeground(NOTIF_ID, notif)

        // you can now connect - this Service will not be killed
        initBleAndConnect()
    }

    private fun initBleAndConnect() {
        // reuse your existing initBle()/connectToDevice() logic,
        // but store the gatt in a member so you can close it later
    }

    override fun onDestroy() {
        gatt?.close()
        super.onDestroy()
    }

    private fun createChannelIfNeeded() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            val nm = getSystemService(NotificationManager::class.java)
            if (nm.getNotificationChannel(CHANNEL_ID) == null) {
                nm.createNotificationChannel(
                    NotificationChannel(
                        CHANNEL_ID, "BLE link",
                        NotificationManager.IMPORTANCE_LOW
                    )
                )
            }
        }
    }
}
