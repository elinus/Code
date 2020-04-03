package com.example.sharedmemorydemo;

import android.os.ParcelFileDescriptor;
import android.os.RemoteException;

import com.example.sharedmemory.ISharedMemory;

public class SharedMemoryImpl extends ISharedMemory.Stub {

    @Override
    public ParcelFileDescriptor OpenSharedMem(String name, int size, boolean create) throws RemoteException {
        return null;
    }
}
