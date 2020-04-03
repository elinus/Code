package com.example.clientsharedmemory;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.ParcelFileDescriptor;
import android.os.RemoteException;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.example.sharedmemory.ISharedMemory;

public class MainActivity extends AppCompatActivity implements ServiceConnection {

    ISharedMemory shmService;
    Button b;
    EditText ed,ed2;
    TextView tv;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bindService(new Intent("com.example.sharedmemorydemo.SharedMemoryService")
                .setPackage("com.example.sharedmemorydemo"),this, BIND_AUTO_CREATE);
        tv = (TextView)findViewById(R.id.tv);
        ed=(EditText)findViewById(R.id.ed);
        ed2 = (EditText)findViewById(R.id.ed2);
        b=(Button)findViewById(R.id.btnGet);
        b.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                tv.setText("val:" + SharedMemoryClientLib.getVal(Integer.parseInt(ed2.getText().toString())));

            }
        });
        Button bset = (Button)findViewById(R.id.btnSet);
        bset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                SharedMemoryClientLib.setVal(Integer.parseInt(ed2.getText().toString()),Integer.parseInt(ed.getText().toString()));
            }
        });
    }

    @Override
    public void onServiceConnected(ComponentName componentName, IBinder iBinder) {
        shmService = ISharedMemory.Stub.asInterface(iBinder);
        try {
            ParcelFileDescriptor p = shmService.OpenSharedMem("sh1", 1000, false);
            SharedMemoryClientLib.setMap(p.getFd(), 1000);
        } catch (RemoteException e) {
            e.printStackTrace();
        }

    }

    @Override
    public void onServiceDisconnected(ComponentName componentName) {

    }
}
