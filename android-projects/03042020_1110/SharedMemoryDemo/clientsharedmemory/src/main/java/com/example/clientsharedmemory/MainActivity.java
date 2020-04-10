package com.example.clientsharedmemory;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.ParcelFileDescriptor;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.example.sharedmemory.ISharedMemory;

public class MainActivity extends Activity {

    public static final String TAG = "ShmClient";

    ISharedMemory iSharedMemory = null;
    ParcelFileDescriptor descriptor = null;

    Button btnSet, btnGet;
    EditText etData;
    TextView tvResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.d(TAG, "onCreate()");

        bindService(new Intent("com.example.sharedmemorydemo.SharedMemoryService")
                        .setPackage("com.example.sharedmemorydemo"),
                connection, BIND_AUTO_CREATE);
        Log.d(TAG, "onCreate - bindService.");

        tvResult = (TextView) findViewById(R.id.tvResult);
        etData = (EditText)  findViewById(R.id.etData);

        btnGet = (Button) findViewById(R.id.btnGet);
        btnGet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                tvResult.setText("Val: " + SharedMemoryClientLib.getVal(descriptor.getFd()));
            }
        });

        btnSet = (Button) findViewById(R.id.btnSet);
        btnSet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                SharedMemoryClientLib.setVal(descriptor.getFd(), Integer.parseInt(etData.getText().toString()));
            }
        });
    }

    private ServiceConnection connection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            Log.d(TAG, "Service connected!");
            iSharedMemory = ISharedMemory.Stub.asInterface(service);
            try {
                descriptor = iSharedMemory.OpenSharedMem("sh1", 1024, false);
                Log.d(TAG, "fd(iSharedMemory.OpenSharedMem) = " + descriptor.getFd());
                SharedMemoryClientLib.setMap(descriptor.getFd(), 1024);
                Log.d(TAG, "fd = " + descriptor.getFd());
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
