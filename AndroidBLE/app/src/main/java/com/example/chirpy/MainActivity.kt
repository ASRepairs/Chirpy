@file:SuppressLint("InlinedApi") // allows using BLUETOOTH_SCAN/CONNECT on minSdk<31

package com.example.chirpy

import android.Manifest
import android.annotation.SuppressLint
import android.bluetooth.*
import android.bluetooth.le.*
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.os.ParcelUuid
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
import androidx.core.content.ContextCompat
import com.google.android.gms.location.LocationServices
import java.nio.charset.StandardCharsets
import java.util.*

class MainActivity : ComponentActivity() {

    companion object {
        private const val SERVICE_UUID = "0000abcd-0000-1000-8000-00805f9b34fb"
        private const val CHAR_UUID = "0000dcba-0000-1000-8000-00805f9b34fb"
    }

    private lateinit var bluetoothAdapter: BluetoothAdapter
    private var bluetoothLeScanner: BluetoothLeScanner? = null
    private var bluetoothGatt: BluetoothGatt? = null
    private var writeCharacteristic: BluetoothGattCharacteristic? = null

    private var devices by mutableStateOf(listOf<BluetoothDevice>())
    private var showDialog by mutableStateOf(false)
    private var isConnected by mutableStateOf(false)
    private var statusText by mutableStateOf("Idle")

    private val permissionLauncher =
        registerForActivityResult(ActivityResultContracts.RequestMultiplePermissions()) { perms ->
            if (perms.values.all { it }) initBle()
            else statusText = "Permissions denied"
        }

    @SuppressLint("MissingPermission")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        permissionLauncher.launch(
            arrayOf(
                Manifest.permission.BLUETOOTH_SCAN,
                Manifest.permission.BLUETOOTH_CONNECT,
                Manifest.permission.ACCESS_FINE_LOCATION
            )
        )

        setContent {
            MaterialTheme {
                Column(
                    modifier = Modifier
                        .fillMaxSize()
                        .padding(24.dp),
                    verticalArrangement = Arrangement.spacedBy(16.dp, Alignment.CenterVertically),
                    horizontalAlignment = Alignment.CenterHorizontally
                ) {
                    Text("BLE GPS Sender", style = MaterialTheme.typography.headlineSmall)

                    Button(
                        onClick = {
                            statusText = "Scanning…"
                            devices = listOf() // reset
                            startScan()
                        },
                        enabled = !isConnected
                    ) {
                        Text("Connect to Watch")
                    }

                    Button(
                        onClick = {
                            statusText = "Sending GPS…"
                            sendLocation { ok -> statusText = if (ok) "Sent!" else "Failed" }
                        },
                        enabled = isConnected
                    ) {
                        Text("Send GPS Coords")
                    }

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

    private fun initBle() {
        val manager = getSystemService(BLUETOOTH_SERVICE) as BluetoothManager
        bluetoothAdapter = manager.adapter
        bluetoothLeScanner = bluetoothAdapter.bluetoothLeScanner
    }

    private fun startScan() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S &&
            ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_SCAN)
            != PackageManager.PERMISSION_GRANTED
        ) return

        val filter = ScanFilter.Builder()
            .setServiceUuid(ParcelUuid(UUID.fromString(SERVICE_UUID)))
            .build()
        val settings = ScanSettings.Builder()
            .setScanMode(ScanSettings.SCAN_MODE_LOW_LATENCY)
            .build()

        bluetoothLeScanner?.startScan(listOf(filter), settings, scanCallback)
    }

    private val scanCallback = object : ScanCallback() {
        @RequiresPermission(Manifest.permission.BLUETOOTH_SCAN)
        override fun onScanResult(callbackType: Int, result: ScanResult) {
            // Explicit runtime check for BLUETOOTH_SCAN permission
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S &&
                ContextCompat.checkSelfPermission(this@MainActivity, Manifest.permission.BLUETOOTH_SCAN)
                != PackageManager.PERMISSION_GRANTED
            ) {
                return
            }

            val device = result.device
            val name = device.name ?: return
            if (!name.startsWith("Chirpy_")) return

            bluetoothLeScanner?.stopScan(this)

            runOnUiThread {
                devices = listOf(device)
                showDialog = true
            }
        }

    }

    @RequiresPermission(Manifest.permission.BLUETOOTH_CONNECT)
    private fun connectToDevice(device: BluetoothDevice) {
        // Runtime permission check for BLUETOOTH_SCAN
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S &&
            ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_SCAN)
            != PackageManager.PERMISSION_GRANTED
        ) {
            return
        }

        bluetoothLeScanner?.stopScan(scanCallback)

        // Runtime permission check for BLUETOOTH_CONNECT
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S &&
            ContextCompat.checkSelfPermission(this, Manifest.permission.BLUETOOTH_CONNECT)
            != PackageManager.PERMISSION_GRANTED
        ) {
            return
        }

        device.connectGatt(this, false, gattCallback)
        statusText = "Connecting to ${device.name ?: "device"}…"
    }
    private val gattCallback = object : BluetoothGattCallback() {
        override fun onConnectionStateChange(g: BluetoothGatt, status: Int, newState: Int) {
            if (newState == BluetoothProfile.STATE_CONNECTED) {
                bluetoothGatt = g

                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S &&
                    ContextCompat.checkSelfPermission(
                        this@MainActivity,
                        Manifest.permission.BLUETOOTH_CONNECT
                    ) == PackageManager.PERMISSION_GRANTED
                ) {
                    g.discoverServices()
                }

                runOnUiThread {
                    isConnected = true
                    statusText = "Connected!"
                }
            } else if (newState == BluetoothProfile.STATE_DISCONNECTED) {
                bluetoothGatt = null
                writeCharacteristic = null

                runOnUiThread {
                    isConnected = false
                    statusText = "Disconnected"
                }
            }
        }

        override fun onServicesDiscovered(g: BluetoothGatt, status: Int) {
            val svc = g.getService(UUID.fromString(SERVICE_UUID))
            writeCharacteristic = svc?.getCharacteristic(UUID.fromString(CHAR_UUID))

            runOnUiThread {
                statusText = if (writeCharacteristic != null) "Ready to send" else "Characteristic not found"
            }
        }
    }

    private fun sendLocation(onDone: (Boolean) -> Unit) {
        val char = writeCharacteristic
        val gatt = bluetoothGatt
        if (char == null || gatt == null) {
            onDone(false)
            return
        }

        if (ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION)
            != PackageManager.PERMISSION_GRANTED
        ) {
            onDone(false)
            return
        }

        val fused = LocationServices.getFusedLocationProviderClient(this)
        fused.lastLocation
            .addOnSuccessListener { loc ->
                if (loc == null) {
                    onDone(false)
                    return@addOnSuccessListener
                }

                val now = Calendar.getInstance()
                val payload = buildString {
                    append(loc.latitude)
                    append(",")
                    append(loc.longitude)
                    append(",")
                    append(now.get(Calendar.YEAR))
                    append(",")
                    append(now.get(Calendar.MONTH) + 1) // Months are 0-based
                    append(",")
                    append(now.get(Calendar.DAY_OF_MONTH))
                    append(",")
                    append(now.get(Calendar.HOUR_OF_DAY))
                    append(",")
                    append(now.get(Calendar.MINUTE))
                    append(",")
                    append(now.get(Calendar.SECOND))
                }

                char.setValue(payload.toByteArray(StandardCharsets.UTF_8))
                val success = gatt.writeCharacteristic(char)
                onDone(success)
            }
            .addOnFailureListener {
                onDone(false)
            }
    }
}
