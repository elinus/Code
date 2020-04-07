package com.example.shmdemoandroidq;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    public static final String TAG = "Shm-Server";
    public static boolean SHM_STATUS = false;
    Button btnCreate, btnDestroy, btnSet, btnGet;
    EditText etDataForShm;
    TextView tvDataFromShm;

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

        btnCreate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SharedMemoryServerLibrary.createShm()) {
                    Log.i(TAG, "Shared memory created successfully!" +
                            "\nDetails ==>> { fd = " + SharedMemoryServerLibrary.getShmFd()
                            + ", size = " + SharedMemoryServerLibrary.getShmSize()
                            + " }");
                    SHM_STATUS = true;
                }
            }
        });

        btnDestroy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SharedMemoryServerLibrary.releaseShm()) {
                    Log.i(TAG, "Shared memory destroyed!!");
                    SHM_STATUS = false;
                }
            }
        });

        btnSet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (SHM_STATUS) {
                    String msg = etDataForShm.getText().toString();
                    if (msg.isEmpty() || msg.equals("")) {
                        Toast.makeText(getApplicationContext(),
                                "Empty data can't be set!", Toast.LENGTH_SHORT).show();
                    } else {
                        SharedMemoryServerLibrary.setShmData(msg);
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
                    String ret_msg = SharedMemoryServerLibrary.getShmData();
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
