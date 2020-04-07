package com.example.shmclientandroidq;

public class SharedMemoryClientLibrary {

    static {
        System.loadLibrary("client-lib");
    }

    public static native boolean mapShm(int fd, int size);
    public static native void setShmData(String data);
    public static native String getShmData();

}
