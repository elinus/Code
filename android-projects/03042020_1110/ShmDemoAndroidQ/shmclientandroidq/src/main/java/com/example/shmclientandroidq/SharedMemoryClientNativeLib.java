package com.example.shmclientandroidq;

import android.os.SharedMemory;

public class SharedMemoryClientNativeLib {

    static {
        System.loadLibrary("client-lib");
    }

    public static native boolean mapShm(int fd, int size);
    public static native void setShmData(String data);
    public static native String getShmData(int data_size);
    public static native boolean mapSharedMemory(SharedMemory shm, int fd, int size);

}
