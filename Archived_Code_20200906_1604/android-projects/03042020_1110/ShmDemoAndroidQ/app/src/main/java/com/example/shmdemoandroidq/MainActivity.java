package com.example.shmdemoandroidq;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.SharedMemory;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    public static final String TAG = "Shm-Server";
    public static boolean SHM_STATUS = false;
    Button btnCreate, btnDestroy, btnSet, btnGet;
    EditText etDataForShm;
    TextView tvDataFromShm, tvSwitchNativeJava;
    Switch switchNativeAndJava;

    private SharedMemory shm = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnCreate = (Button) findViewById(R.id.create);
        btnDestroy = (Button) findViewById(R.id.destroy);
        btnSet = (Button) findViewById(R.id.set_data);
        btnGet = (Button) findViewById(R.id.get_data);
        etDataForShm = (EditText) findViewById(R.id.data_for_shm);
        tvDataFromShm = (TextView) findViewById(R.id.data_from_shm);
        tvSwitchNativeJava = (TextView) findViewById(R.id.switch_native_java_text);
        switchNativeAndJava = (Switch) findViewById(R.id.switch_native_java);

        switchNativeAndJava.setChecked(false);
        switchNativeAndJava.setEnabled(false);
        btnGet.setEnabled(false);

//        switchNativeAndJava.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
//            @Override
//            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
//                if (isChecked) {
//                    btnGet.setEnabled(false);
//                    tvSwitchNativeJava.setText(switchNativeAndJava.getTextOn());
//                } else {
//                    btnGet.setEnabled(true);
//                    tvSwitchNativeJava.setText(switchNativeAndJava.getTextOff());
//                }
//            }
//        });

        btnCreate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if (switchNativeAndJava.isChecked()) {
                    shm = SharedMemoryProducer.createShm("SysIntShm", 1024);
                    if (shm != null) {
                        Log.i(TAG, "<os.SharedMemory> created successfully. " +
                                "Size = " + shm.getSize());
                        SHM_STATUS = true;
                    }
                } else {
                    if (SharedMemoryServerNativeLib.createShm()) {
                        Log.i(TAG, "Shared memory created successfully!" +
                            "\nDetails => { fd = " + SharedMemoryServerNativeLib.getShmFd()
                            + ", size = " + SharedMemoryServerNativeLib.getShmSize()
                            + " }");
                        SHM_STATUS = true;
                    }
                }

            }
        });

        btnDestroy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if (switchNativeAndJava.isChecked()) {
                    if (SharedMemoryProducer.releaseShm()) {
                        Log.i(TAG, "<os.SharedMemory> destroyed!!");
                        SHM_STATUS = false;
                    }
                } else {
                    if (SharedMemoryServerNativeLib.releaseShm()) {
                        Log.i(TAG, "Shared memory destroyed!!");
                        SHM_STATUS = false;
                    }
                }
            }
        });

        btnSet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SHM_STATUS) {
                    String msg = etDataForShm.getText().toString();
                    if (msg.equals("") || msg.isEmpty()) {
                        Toast.makeText(getApplicationContext(),
                                "Empty data can't be set!", Toast.LENGTH_SHORT).show();
                    } else {
                        if (switchNativeAndJava.isChecked()) {
                            SharedMemoryProducer.setShmData(msg);
                        } else {
                            SharedMemoryServerNativeLib.setShmData(msg);
                        }
                    }
                } else {
                    Toast.makeText(getApplicationContext(),
                            "Shared memory destroyed!", Toast.LENGTH_SHORT).show();
                }
            }
        });

        btnGet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SHM_STATUS) {
                    String ret_msg = "";
                    if (switchNativeAndJava.isChecked()) {
                        ret_msg = SharedMemoryProducer.getShmData();
                    } else {
                        ret_msg = SharedMemoryServerNativeLib.getShmData();
                    }
                    if (ret_msg.isEmpty() || ret_msg.equals("")) {
                        Toast.makeText(getApplicationContext(),
                                "Empty data!", Toast.LENGTH_SHORT).show();
                    } else {
                        tvDataFromShm.setText(ret_msg);
                    }
                } else {
                    Toast.makeText(getApplicationContext(),
                            "Shared memory destroyed!", Toast.LENGTH_SHORT).show();
                }
            }
        });

    }

}
