package com.example.shmclientandroidq;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.SharedMemory;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import com.example.sharedmemoryservice.ISharedMemoryService;
import com.example.shmlib.IShmMap;

public class MainActivity extends AppCompatActivity {

    public static final String TAG = "Shm-Client";
    public static boolean SHM_MAP_STATUS = false;

    Button btnSet, btnGet;
    EditText etDataForShm;
    TextView tvDataFromShm, tvDataFromShmNative, tvSwitchNativeJava;
    Switch switchNativeAndJava;;

    IShmMap iShmMap = null;

    int shmFd = -1;
    int shmSize = -1;

    ISharedMemoryService iSharedMemoryService = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bindService(new Intent("com.example.shmdemoandroidq.SharedMemoryServerService")
                        .setPackage("com.example.shmdemoandroidq"),
                shmSvcConn, BIND_AUTO_CREATE);
        Log.d(TAG, "onCreate() - SharedMemoryServerService bindService done.");

//        bindService(new Intent("com.example.shmdemoandroidq.ShmMapService")
//                .setPackage("com.example.shmdemoandroidq"), connection, BIND_AUTO_CREATE);
//        Log.d(TAG, "onCreate() - ShmMapService bindService done.");

        btnSet = (Button) findViewById(R.id.setData);
        btnGet = (Button) findViewById(R.id.getData);
        etDataForShm = (EditText) findViewById(R.id.dataForShm);
        tvDataFromShm = (TextView) findViewById(R.id.dataFromShm);
        tvDataFromShmNative = (TextView) findViewById(R.id.dataFromShmNative);
        tvSwitchNativeJava = (TextView) findViewById(R.id.switch_native_java_text);
        switchNativeAndJava = (Switch) findViewById(R.id.switch_native_java);

        switchNativeAndJava.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked) {
                    btnSet.setEnabled(false);
                    etDataForShm.setEnabled(false);
                    tvSwitchNativeJava.setText(switchNativeAndJava.getTextOn());

                } else {btnGet.setEnabled(true);
                    btnSet.setEnabled(true);
                    etDataForShm.setEnabled(true);
                    tvSwitchNativeJava.setText(switchNativeAndJava.getTextOff());
                }
            }
        });

        btnSet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SHM_MAP_STATUS) {
                    String msg = etDataForShm.getText().toString();
                    if (msg.isEmpty() || msg.equals("")) {
                        Toast.makeText(getApplicationContext(),
                                "Empty data can't be set!", Toast.LENGTH_SHORT).show();
                    } else {
                        if (switchNativeAndJava.isChecked()) {
                            SharedMemoryConsumer.setShmData(msg);
                        } else {
                            SharedMemoryClientNativeLib.setShmData(msg);
                        }
                    }
                } else {
                    Toast.makeText(getApplicationContext(),
                            "Shared memory not mapped!", Toast.LENGTH_SHORT).show();
                }
            }
        });


        btnGet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SHM_MAP_STATUS) {
                    String ret_msg = "";
                    String ret_msg_nat = "";
                    if (switchNativeAndJava.isChecked()) {
                        ret_msg = SharedMemoryConsumer.getShmData();
                        ret_msg_nat = SharedMemoryClientNativeLib
                                .getShmData(SharedMemoryConsumer.BYTE_BUFFER_DATA_LENGTH);
                    } else {
                        ret_msg = SharedMemoryClientNativeLib.getShmData(-1);
                    }

                    if (ret_msg.isEmpty() || ret_msg.equals("")) {
                        Toast.makeText(getApplicationContext(),
                                "Empty data!", Toast.LENGTH_SHORT).show();
                    } else {
                        tvDataFromShm.setText(ret_msg);
                        tvDataFromShmNative.setText(ret_msg_nat);
                    }
                } else {
                    Toast.makeText(getApplicationContext(),
                            "Shared memory not mapped!", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private void showShmMapToast(boolean success) {
        if (success) {
            SHM_MAP_STATUS = true;
            Log.i(TAG, "Shared memory mapping success!");
            Toast.makeText(getApplicationContext(),
                    "Shm mapping success!", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(getApplicationContext(),
                    "Shared memory not mapped!", Toast.LENGTH_SHORT).show();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (iSharedMemoryService == null) return;
        try {
            SharedMemoryConsumer.BYTE_BUFFER_DATA_LENGTH =
                    iSharedMemoryService.getByteBufferDataLength();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    private ServiceConnection connection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            Log.d(TAG, "Service connected!");
            iShmMap = IShmMap.Stub.asInterface(service);
            try {
                shmFd = iShmMap.getShmFd().getFd();
                shmSize = iShmMap.getShmSize();
                if (SharedMemoryClientNativeLib.mapShm(shmFd, shmSize)) {
                    showShmMapToast(true);
                } else {
                    showShmMapToast(false);
                }

            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            Log.d(TAG, "Service disconnected!");
        }
    };

    ServiceConnection shmSvcConn = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            Log.d(TAG, "Service <SvcConn> connected!");
            iSharedMemoryService = ISharedMemoryService.Stub.asInterface(service);
            try {
                SharedMemory shm = iSharedMemoryService.getShm("SysIntSharedMemory", 1024);
                if (SharedMemoryConsumer.mapShm(shm, shm.getSize())) {
                    showShmMapToast(true);
                } else {
                    showShmMapToast(false);
                }
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            Log.d(TAG, "Service <SvcConn> disconnected!");
        }
    };
}
