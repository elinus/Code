package com.example.sharedmemorydemo;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

public class SharedMemoryService extends Service {

    public SharedMemoryService() {
    }

    @Override
    public IBinder onBind(Intent intent) {
        return new SharedMemoryImpl();
    }
}
