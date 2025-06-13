@file:SuppressLint("InlinedApi")   // lets us reference SCAN / CONNECT on <31
package com.example.chirpy

import android.Manifest
import android.annotation.SuppressLint
import android.app.NotificationChannel
import android.app.NotificationManager
import android.app.PendingIntent
import android.bluetooth.*
import android.bluetooth.le.*
import android.content.Intent
import android.content.pm.PackageManager
import androidx.core.app.Person
import androidx.core.graphics.drawable.IconCompat
import android.graphics.BitmapFactory
import android.net.Uri
import android.os.Build
import android.os.Bundle
import android.os.Handler
import android.os.ParcelUuid
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.result.contract.ActivityResultContracts
import androidx.annotation.RequiresPermission
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.core.app.NotificationCompat
import androidx.core.content.ContextCompat
import com.google.android.gms.location.LocationServices
import java.nio.charset.StandardCharsets
import java.util.*

class MainActivity : ComponentActivity() {

    companion object {
        private const val SERVICE_UUID = "0000abcd-0000-1000-8000-00805f9b34fb"
        private const val CHAR_UUID    = "0000dcba-0000-1000-8000-00805f9b34fb"
        private const val NOTIFY_UUID = "0000dcb1-0000-1000-8000-00805f9b34fb"
        private val CCC_UUID = UUID.fromString("00002902-0000-1000-8000-00805f9b34fb")
    }

    private lateinit var bluetoothAdapter: BluetoothAdapter
    private var bluetoothLeScanner: BluetoothLeScanner? = null
    private var bluetoothGatt: BluetoothGatt? = null
    private var writeCharacteristic: BluetoothGattCharacteristic? = null
    private var notifyCharacteristic: BluetoothGattCharacteristic? = null   // NEW

    private var devices       by mutableStateOf(listOf<BluetoothDevice>())
    private var showDialog    by mutableStateOf(false)
    private var isConnected   by mutableStateOf(false)
    private var statusText    by mutableStateOf("Idle")

    /* ──────────────────────────── SET-UP UI & PERMS ─────────────────────────── */

    private val permissionLauncher =
        registerForActivityResult(ActivityResultContracts.RequestMultiplePermissions()) { perms ->
            if (perms.values.all { it }) initBle() else statusText = "Permissions denied"
        }
    private val qrLauncher = registerForActivityResult(ActivityResultContracts.StartActivityForResult()) { result ->
        val contents = result.data?.getStringExtra("SCAN_RESULT") ?: return@registerForActivityResult
        scanForDeviceWithAddress(contents)
    }


    @SuppressLint("MissingPermission")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        permissionLauncher.launch(
            arrayOf(
                Manifest.permission.BLUETOOTH_SCAN,
                Manifest.permission.BLUETOOTH_CONNECT,
                Manifest.permission.ACCESS_FINE_LOCATION,
                Manifest.permission.POST_NOTIFICATIONS
            )
        )

        setContent {
            MaterialTheme {
                Column(
                    Modifier.fillMaxSize().padding(24.dp),
                    Arrangement.spacedBy(16.dp, Alignment.CenterVertically),
                    Alignment.CenterHorizontally
                ) {
                    Text("Chirpy Client", style = MaterialTheme.typography.headlineSmall)

                    Button(
                        onClick = {
                            val intent = Intent(this@MainActivity, QrScanActivity::class.java)
                            qrLauncher.launch(intent)
                        },
                        enabled = !isConnected
                    ) { Text("Connect to Watch") }

                    Button(
                        onClick = {
                            statusText = "Sending GPS…"
                            sendGps { ok ->
                                statusText = if (ok) "Sent!" else "Failed"
                            }
                        },
                        enabled = isConnected
                    ) { Text("Send GPS to Watch") }

                    Text(statusText)
                }

                if (showDialog) {
                    AlertDialog(
                        onDismissRequest = { showDialog = false },
                        confirmButton = {},
                        title = { Text("Select Watch") },
                        text = {
                            Column {
                                devices.forEach { device ->
                                    Text(
                                        text = device.name ?: "Unknown",
                                        modifier = Modifier
                                            .fillMaxWidth()
                                            .padding(8.dp)
                                            .clickable {
                                                connectToDevice(device)
                                                showDialog = false
                                            }
                                    )
                                }
                            }
                        }
                    )
                }
            }
        }
    }

    /* ──────────────────────────── BLE BASIC HELPERS ─────────────────────────── */

    private fun initBle() {
        val mgr = getSystemService(BLUETOOTH_SERVICE) as BluetoothManager
        bluetoothAdapter    = mgr.adapter
        bluetoothLeScanner  = bluetoothAdapter.bluetoothLeScanner
    }

    private fun startScan() {
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_SCAN)
            != PackageManager.PERMISSION_GRANTED
        ) {
            statusText = "Scan permission not granted"
            return
        }

        val filter = ScanFilter.Builder()
            .setServiceUuid(ParcelUuid(UUID.fromString(SERVICE_UUID)))
            .build()
        val settings = ScanSettings.Builder()
            .setScanMode(ScanSettings.SCAN_MODE_LOW_LATENCY)
            .build()

        bluetoothLeScanner?.startScan(listOf(filter), settings, scanCallback)
    }
    private fun scanForDeviceWithAddress(targetName: String) {
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_SCAN)
            != PackageManager.PERMISSION_GRANTED
        ) {
            statusText = "Scan permission not granted"
            return
        }

        statusText = "Looking for $targetName"

        val callback = object : ScanCallback() {
            override fun onScanResult(callbackType: Int, result: ScanResult) {
                val device = result.device
                val name = device.name

                // Log every device to help debug
                Log.d("BLE_SCAN", "Found: ${name ?: "Unnamed"} @ ${device.address}")

                if (name != null && name.equals(targetName, ignoreCase = true)) {
                    bluetoothLeScanner?.stopScan(this)
                    connectToDevice(device)
                }
            }
        }

        bluetoothLeScanner?.startScan(
            null,
            ScanSettings.Builder().setScanMode(ScanSettings.SCAN_MODE_LOW_LATENCY).build(),
            callback
        )

        Handler(mainLooper).postDelayed({
            bluetoothLeScanner?.stopScan(callback)
            if (!isConnected) {
                statusText = "Device not found"
            }
        }, 10000)
    }

    private val scanCallback = object : ScanCallback() {
        @RequiresPermission(Manifest.permission.BLUETOOTH_SCAN)
        override fun onScanResult(type: Int, result: ScanResult) {
            if (ContextCompat.checkSelfPermission(this@MainActivity, Manifest.permission.BLUETOOTH_SCAN)
                != PackageManager.PERMISSION_GRANTED
            ) return

            val dev = result.device
            val nm = dev.name ?: return
            if (!nm.startsWith("Chirpy_")) return

            bluetoothLeScanner?.stopScan(this)
            runOnUiThread {
                devices = listOf(dev)
                showDialog = true
            }
        }
    }

    /* ─────────────────────────── CONNECT & DISCOVER ─────────────────────────── */

    @RequiresPermission(Manifest.permission.BLUETOOTH_CONNECT)
    private fun connectToDevice(device: BluetoothDevice) {
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_CONNECT)
            != PackageManager.PERMISSION_GRANTED
        ) {
            statusText = "Connect permission not granted"
            return
        }

        bluetoothLeScanner?.stopScan(scanCallback)
        statusText = "Connecting to ${device.name ?: "device"}…"
        device.connectGatt(this, false, gattCallback)
    }

    private val gattCallback = object : BluetoothGattCallback() {

        override fun onConnectionStateChange(gatt: BluetoothGatt, status: Int, newState: Int) {
            if (newState == BluetoothProfile.STATE_CONNECTED) {
                bluetoothGatt = gatt
                if (ContextCompat.checkSelfPermission(this@MainActivity, Manifest.permission.BLUETOOTH_CONNECT)
                    == PackageManager.PERMISSION_GRANTED
                ) {
                    gatt.requestMtu(100)
                } else {
                    runOnUiThread {
                        statusText = "Missing permission: cannot discover services"
                    }
                }

                runOnUiThread {
                    isConnected = true
                    statusText  = "Connected!"
                }
                Handler(mainLooper).postDelayed({
                    sendTime { ok ->
                        runOnUiThread {
                            statusText = if (ok) "Time sent ✅" else "Time send ❌"
                            Handler(mainLooper).postDelayed({
                                statusText = "Connected!"
                            }, 1500)
                        }
                    }
                }, 1000)
            } else if (newState == BluetoothProfile.STATE_DISCONNECTED) {
                bluetoothGatt       = null
                writeCharacteristic = null
                notifyCharacteristic = null
                runOnUiThread {
                    isConnected = false
                    statusText  = "Disconnected"
                }
            }
        }
        override fun onMtuChanged(gatt: BluetoothGatt, mtu: Int, status: Int) {
            if (status == BluetoothGatt.GATT_SUCCESS) {
                Log.d("BLE", "MTU negotiated: $mtu bytes")
                // Now it’s safe to discover services
                gatt.discoverServices()
            } else {
                // Fallback to default MTU
                gatt.discoverServices()
            }
        }

        override fun onServicesDiscovered(gatt: BluetoothGatt, status: Int) {
            val svc  = gatt.getService(UUID.fromString(SERVICE_UUID))
            writeCharacteristic  = svc?.getCharacteristic(UUID.fromString(CHAR_UUID))
            notifyCharacteristic = svc?.getCharacteristic(UUID.fromString(NOTIFY_UUID))   // NEW

            // ── enable notifications if characteristic found
            notifyCharacteristic?.let { ch ->
                if (ContextCompat.checkSelfPermission(this@MainActivity, Manifest.permission.BLUETOOTH_CONNECT)
                    != PackageManager.PERMISSION_GRANTED
                ) return

                gatt.setCharacteristicNotification(ch, true)
                val ccc = ch.getDescriptor(CCC_UUID)
                if (ccc != null) {
                    ccc.value = BluetoothGattDescriptor.ENABLE_NOTIFICATION_VALUE
                    gatt.writeDescriptor(ccc)
                } else {
                    runOnUiThread { statusText = "Notify descriptor missing" }
                }

            }

            runOnUiThread {
                statusText =
                    if (writeCharacteristic != null) "Ready" else "Characteristic missing"
            }
        }

        /* ──────────────  HANDLE INCOMING NOTIFICATIONS  ────────────── */
        override fun onCharacteristicChanged(
            gatt: BluetoothGatt,
            characteristic: BluetoothGattCharacteristic
        ) {
            if (characteristic.uuid.toString().equals(NOTIFY_UUID, ignoreCase = true)) {
                val msg = characteristic.getStringValue(0)
                Log.d("BLE_RAW", "Received: $msg")
                when {
                    msg == "REQ:GPS" -> {
                        sendGps {
                            runOnUiThread {
                                statusText = if (it) "Sent GPS!" else "Send GPS FAILED"
                            }
                        }
                    }

                    msg == "REQ:TIME" -> {
                        sendTime {
                            runOnUiThread {
                                statusText = if (it) "Sent Time!" else "Send Time FAILED"
                            }
                        }
                    }

                    msg.startsWith("GPS:") -> {
                        val gpsPayload = msg.removePrefix("GPS:")
                        val parts = gpsPayload.split(':', ',')
                        if (parts.size == 3) {
                            val userId = parts[0].toIntOrNull()
                            val lat = parts[1]
                            val lon = parts[2]
                            runOnUiThread {
                                showGpsNotification(lat, lon, userId)
                                statusText = "Received GPS!"
                            }
                        } else {
                            runOnUiThread { statusText = "Bad GPS format :(" }
                        }
                    }
                    msg.startsWith("ALERT:") -> {
                        val alertPayload = msg.removePrefix("ALERT:")
                        val parts = alertPayload.split(':', ',')

                        if (parts.size == 3) {
                            val userId = parts[0].toIntOrNull()
                            val lat = parts[1]
                            val lon = parts[2]
                            runOnUiThread {
                                showAlertNotification(lat, lon, userId)
                                statusText = "Received ALERT!"
                            }
                        } else {
                            runOnUiThread { statusText = "Bad ALERT format :(" }
                        }
                    }


                    else -> {
                        runOnUiThread {
                            statusText = "Unknown BLE msg: $msg"
                        }
                    }
                }
            }
        }
    }

    /* ─────────────────────────── WRITE (GPS + DATE) ─────────────────────────── */

    private fun sendGps(onDone: (Boolean) -> Unit) {
        val ch = writeCharacteristic
        val gatt = bluetoothGatt
        if (ch == null || gatt == null) { onDone(false); return }

        if (ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION)
            != PackageManager.PERMISSION_GRANTED
        ) { onDone(false); return }
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_CONNECT)
            != PackageManager.PERMISSION_GRANTED
        ) { onDone(false); return }
        val fused = LocationServices.getFusedLocationProviderClient(this)
        fused.lastLocation
            .addOnSuccessListener { loc ->
                if (loc == null) { onDone(false); return@addOnSuccessListener }

                val payload = "${loc.latitude},${loc.longitude}"
                ch.setValue(payload.toByteArray(StandardCharsets.UTF_8))
                onDone(gatt.writeCharacteristic(ch))
            }
            .addOnFailureListener { onDone(false) }
    }

    private fun sendTime(onDone: (Boolean) -> Unit) {
        val ch = writeCharacteristic
        val gatt = bluetoothGatt
        if (ch == null || gatt == null) { onDone(false); return }

        if (ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_CONNECT)
            != PackageManager.PERMISSION_GRANTED
        ) { onDone(false); return }

        val now = Calendar.getInstance()
        val payload = buildString {
            append(now.get(Calendar.YEAR)); append(',')
            append(now.get(Calendar.MONTH) + 1); append(',')
            append(now.get(Calendar.DAY_OF_MONTH)); append(',')
            append(now.get(Calendar.HOUR_OF_DAY)); append(',')
            append(now.get(Calendar.MINUTE));      append(',')
            append(now.get(Calendar.SECOND))
        }
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_CONNECT)
            != PackageManager.PERMISSION_GRANTED
        ) { onDone(false); return }

        ch.setValue(payload.toByteArray(StandardCharsets.UTF_8))
        onDone(gatt.writeCharacteristic(ch))
    }
    private fun getSenderImage(userId: Int): Int {
        return when (userId) {
            0 -> R.drawable.froggy
            1 -> R.drawable.piggy
            2 -> R.drawable.horsy
            3 -> R.drawable.pandy
            4 -> R.drawable.lizzy
            5 -> R.drawable.phoeny
            6 -> R.drawable.puppy
            7 -> R.drawable.kitty
            else -> R.drawable.froggy
        }
    }

    private fun showGpsNotification(lat: String, lon: String, userId: Int?) {
        val channelId = "gps_channel"
        val nm = getSystemService(NotificationManager::class.java)

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O &&
            nm.getNotificationChannel(channelId) == null) {
            nm.createNotificationChannel(
                NotificationChannel(channelId, "GPS", NotificationManager.IMPORTANCE_DEFAULT)
            )
        }

        val geoUri = Uri.parse("geo:$lat,$lon?q=$lat,$lon")
        val mapsIntent = Intent(Intent.ACTION_VIEW, geoUri).apply {
            flags = Intent.FLAG_ACTIVITY_NEW_TASK
        }

        val pi = PendingIntent.getActivity(
            this, 0, mapsIntent,
            PendingIntent.FLAG_UPDATE_CURRENT or PendingIntent.FLAG_IMMUTABLE
        )

        val senderIcon = IconCompat.createWithResource(this, getSenderImage(userId ?: -1))
        val person = Person.Builder()
            .setName(getUserName(userId))
            .setIcon(senderIcon)
            .build()

        val style = NotificationCompat.MessagingStyle(person)
            .setConversationTitle("${getUserName(userId)} has sent a GPS location")
            .addMessage("Tap to open in Maps!", System.currentTimeMillis(), person)

        val notif = NotificationCompat.Builder(this, channelId)
            .setSmallIcon(R.drawable.ic_stat_name)  // App icon in status bar
            .setStyle(style)
            .setContentIntent(pi)
            .setCategory(NotificationCompat.CATEGORY_MESSAGE)
            .setAutoCancel(true)
            .build()

        nm.notify((System.currentTimeMillis() % Int.MAX_VALUE).toInt(), notif)
    }

    private fun showAlertNotification(lat: String, lon: String, userId: Int?) {
        val channelId = "alert_channel"
        val nm = getSystemService(NotificationManager::class.java)

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O &&
            nm.getNotificationChannel(channelId) == null) {
            val chan = NotificationChannel(
                channelId, "Alerts", NotificationManager.IMPORTANCE_HIGH
            )
            chan.enableLights(true)
            chan.lightColor = android.graphics.Color.RED
            chan.enableVibration(true)
            nm.createNotificationChannel(chan)
        }

        val geoUri = Uri.parse("geo:$lat,$lon?q=$lat,$lon")
        val mapsIntent = Intent(Intent.ACTION_VIEW, geoUri).apply {
            flags = Intent.FLAG_ACTIVITY_NEW_TASK
        }

        val pi = PendingIntent.getActivity(
            this, 0, mapsIntent,
            PendingIntent.FLAG_UPDATE_CURRENT or PendingIntent.FLAG_IMMUTABLE
        )
        val senderIcon = IconCompat.createWithResource(this, getSenderImage(userId ?: -1))

        val person = Person.Builder()
            .setName(getUserName(userId))
            .setIcon(senderIcon)
            .build()

        val style = NotificationCompat.MessagingStyle(person)
            .setConversationTitle("🚨 ${getUserName(userId)} HAS AN EMERGENCY!")
            .addMessage("TAP TO SEE THEIR LOCATION!", System.currentTimeMillis(), person)

        val notif = NotificationCompat.Builder(this, channelId)
            .setSmallIcon(R.drawable.ic_stat_name)  // App icon for status bar
            .setStyle(style)
            .setContentIntent(pi)
            .setColor(android.graphics.Color.RED)
            .setCategory(NotificationCompat.CATEGORY_MESSAGE)
            .setAutoCancel(true)
            .setVibrate(longArrayOf(0, 2000)) // vibrate 2s
            .build()


        nm.notify((System.currentTimeMillis() % Int.MAX_VALUE).toInt(), notif)
    }

    private fun getUserName(userId: Int?): String = when (userId) {
        0 -> "Froggy"
        1 -> "Piggy"
        2 -> "Horsy"
        3 -> "Pandy"
        4 -> "LIZZY"
        5 -> "Phoeny"
        6 -> "Puppy"
        7 -> "Kitty"
        else -> "Someone"
    }


}
