package com.elinus.clientserviceapplication;

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

import com.elinus.simplemathlib.ISimpleMath;

public class MainActivity extends AppCompatActivity implements ServiceConnection {

    private ISimpleMath smService;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button btn1 = findViewById(R.id.Button1);
        btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Log.d("MyServiceTag", "Result :: " + smService.add(14, 20));
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
        smService = ISimpleMath.Stub.asInterface(service);
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {
        smService = null;
    }

    @Override
    protected void onStart() {
        super.onStart();
        bindService(new Intent("com.elinus.serverserviceapp.MySimpService")
                .setPackage("com.elinus.serverserviceapp"), this, BIND_AUTO_CREATE);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (smService != null) {
           smService = null;
        }
    }
}
