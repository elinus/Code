package com.example.sharedmemorydemo;

import android.os.ParcelFileDescriptor;
import android.os.RemoteException;

import com.example.sharedmemory.ISharedMemory;

import java.io.IOException;

public class SharedMemoryImpl extends ISharedMemory.Stub {

    @Override
    public ParcelFileDescriptor OpenSharedMem(String name, int size, boolean create) throws RemoteException {
        int fd = SharedMemoryLib.OpenSharedMem(name, size, create);
        try {
            return ParcelFileDescriptor.fromFd(fd);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
}
