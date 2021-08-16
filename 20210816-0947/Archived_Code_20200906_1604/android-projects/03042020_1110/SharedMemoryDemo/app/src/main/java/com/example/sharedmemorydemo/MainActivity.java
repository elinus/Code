package com.example.sharedmemorydemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    public static final String TAG = "ShmServer";

    EditText etData;
    Button btnSet, btnGet;
    TextView tvResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final int fd = SharedMemoryLib.OpenSharedMem("sh1",1024,true);
        Log.i(TAG, "onCreate() , fd :: " + fd);

        etData = (EditText) findViewById(R.id.etData);

        tvResult = (TextView) findViewById(R.id.tvResult);

        btnSet = (Button) findViewById(R.id.btnSet);
        btnSet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                SharedMemoryLib.setValue(fd, Integer.parseInt(etData.getText().toString()));
            }
        });

        btnGet = (Button) findViewById(R.id.btnGet);
        btnGet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int res = SharedMemoryLib.getValue(fd);
                tvResult.setText("res: " + res);
            }
        });

    }
}
