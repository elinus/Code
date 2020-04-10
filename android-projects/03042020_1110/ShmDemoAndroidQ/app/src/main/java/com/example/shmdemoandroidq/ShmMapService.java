package com.example.shmdemoandroidq;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

import androidx.annotation.Nullable;

public class ShmMapService extends Service {
    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        Log.d(MainActivity.TAG, "onBind() :: " + ShmMapService.class.getSimpleName());
        return new ShmMapImpl();
    }
}
