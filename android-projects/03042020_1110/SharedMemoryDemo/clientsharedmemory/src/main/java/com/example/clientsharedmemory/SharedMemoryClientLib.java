package com.example.clientsharedmemory;

public class SharedMemoryClientLib {

    static {
        System.loadLibrary("client-lib");
    }

    public static native int setVal(int pos, int val);
    public static native int getVal(int pos);
    public static native void setMap(int fd , int size);

}
