package com.example.shmclientandroidq;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.example.shmlib.IShmMap;

public class MainActivity extends AppCompatActivity {

    public static final String TAG = "Shm-Client";
    public static boolean SHM_MAP_STATUS = false;

    Button btnSet, btnGet;
    EditText etDataForShm;
    TextView tvDataFromShm;

    IShmMap iShmMap = null;
    int shmFd = -1;
    int shmSize = -1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bindService(new Intent("com.example.shmdemoandroidq.ShmMapService")
                        .setPackage("com.example.shmdemoandroidq"),
                connection, BIND_AUTO_CREATE);
        Log.d(TAG, "onCreate() - bindService done.");

        btnSet = (Button) findViewById(R.id.setData);
        btnGet = (Button) findViewById(R.id.getData);
        etDataForShm = (EditText) findViewById(R.id.dataForShm);
        tvDataFromShm = (TextView) findViewById(R.id.dataFromShm);

        btnSet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SHM_MAP_STATUS) {
                    String msg = etDataForShm.getText().toString();
                    if (msg.isEmpty() || msg.equals("")) {
                        Toast.makeText(getApplicationContext(),
                                "Empty data can't be set!", Toast.LENGTH_SHORT).show();
                    } else {
                        SharedMemoryClientLibrary.setShmData(msg);
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
                    String ret_msg = SharedMemoryClientLibrary.getShmData();
                    if (ret_msg.isEmpty() || ret_msg.equals("")) {
                        Toast.makeText(getApplicationContext(),
                                "Empty data!", Toast.LENGTH_SHORT).show();
                    } else {
                        tvDataFromShm.setText(ret_msg);
                    }
                } else {
                    Toast.makeText(getApplicationContext(),
                            "Shared memory not mapped!", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private ServiceConnection connection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            Log.d(TAG, "Service connected!");
            iShmMap = IShmMap.Stub.asInterface(service);
            try {
                shmFd = iShmMap.getShmFd().getFd();
                shmSize = iShmMap.getShmSize();
                if (SharedMemoryClientLibrary.mapShm(shmFd, shmSize)) {
                    SHM_MAP_STATUS = true;
                    Log.i(TAG, "Shared memory mapping success!");
                    Toast.makeText(getApplicationContext(),
                            "Shm mapping success!", Toast.LENGTH_SHORT).show();
                    Log.d(TAG, "shm-details :: fd = " + shmFd
                            + ", size = " + shmSize);
                } else {
                    Toast.makeText(getApplicationContext(),
                            "Shared memory not mapped!", Toast.LENGTH_SHORT).show();
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
}
