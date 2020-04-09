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
        public SharedMemory getShm(String name, int size) throws RemoteException {
            return SharedMemoryProducer.createShm(name, size);
        }

        @Override
        public int getByteBufferDataLength() throws RemoteException {
            return SharedMemoryProducer.BYTE_BUFFER_DATA_LENGTH;
        }

    }
}
