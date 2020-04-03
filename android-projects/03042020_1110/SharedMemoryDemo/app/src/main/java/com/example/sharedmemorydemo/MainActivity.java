package com.example.sharedmemorydemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    EditText edpos, edval;
    Button bn;
    TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        SharedMemoryLib.OpenSharedMem("sh1",1000,true);

        edpos = (EditText)findViewById(R.id.ed2);
        edval = (EditText)findViewById(R.id.ed);

        tv=(TextView)findViewById(R.id.tv);
        bn = (Button)findViewById(R.id.btnSet);
        bn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                SharedMemoryLib.setValue("sh1",Integer.parseInt(edpos.getText().toString()),Integer.parseInt(edval.getText().toString()));
            }
        });

        Button bget = (Button)findViewById(R.id.btnGet);
        bget.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int res = SharedMemoryLib.getValue("sh1",Integer.parseInt(edpos.getText().toString()));
                tv.setText("res:"+ res);

            }
        });

    }
}
