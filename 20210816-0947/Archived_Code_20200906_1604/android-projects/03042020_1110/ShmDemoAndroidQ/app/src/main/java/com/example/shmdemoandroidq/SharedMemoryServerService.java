package com.example.shmdemoandroidq;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.SharedMemory;
import android.util.Log;

import com.example.sharedmemoryservice.ISharedMemoryService;

public class SharedMemoryServerService extends Service {

    @Override
    public IBinder onBind(Intent intent) {
        Log.d(MainActivity.TAG, "onBind() :: "
                + SharedMemoryServerService.class.getSimpleName());
        return new SharedMemoryServerServiceImpl();
    }

    private static class SharedMemoryServerServiceImpl extends ISharedMemoryService.Stub {

        @Override
        public SharedMemory getShm() throws RemoteException {
            return SharedMemoryProducer.getShm();
        }

        @Override
        public int getShmSize() throws RemoteException {
            return SharedMemoryProducer.getShmSize();
        }

        @Override
        public String getShmName() throws RemoteException {
            return SharedMemoryProducer.getShmName();
        }

        @Override
        public int getShmOffset() throws RemoteException {
            return 0;
        }
    }
}
