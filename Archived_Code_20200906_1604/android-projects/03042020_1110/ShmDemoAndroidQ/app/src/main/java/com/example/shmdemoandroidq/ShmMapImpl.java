package com.example.shmdemoandroidq;

import android.os.ParcelFileDescriptor;
import android.os.RemoteException;
import android.util.Log;

import com.example.shmlib.IShmMap;

import java.io.IOException;

public class ShmMapImpl extends IShmMap.Stub {

    @Override
    public ParcelFileDescriptor getShmFd() throws RemoteException {
        int fd = SharedMemoryServerNativeLib.getShmFd();
        try {
            Log.d(MainActivity.TAG, "getShmFd :: fd = " + fd);
            return ParcelFileDescriptor.fromFd(fd);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public int getShmSize() throws RemoteException {
        int size = SharedMemoryServerNativeLib.getShmSize();
        Log.d(MainActivity.TAG, "getShmSize :: size = " + size);
        return size;
    }
}
