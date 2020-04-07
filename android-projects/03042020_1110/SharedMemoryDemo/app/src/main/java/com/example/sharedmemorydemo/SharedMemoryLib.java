package com.example.sharedmemorydemo;

import android.util.Log;

public class SharedMemoryLib {

    static {
        System.loadLibrary("native-lib");
    }

    static int fd_ = -1;

    public static int OpenSharedMem(String name, int size, boolean create)  {
        Log.d(MainActivity.TAG, "OpenSharedMem() :: name = " + name + ", size = " + size
                + ", create = " + create);
        if (!create) return fd_;
        if (fd_ != -1) return fd_;
        fd_ = getFD(name, size);
        return fd_;
    }

    public static int setValue(int fd, int val){
        Log.d(MainActivity.TAG, "setValue() :: fd = " + fd + ", val = " + val);
        return setVal(fd, val);
    }

    public static int getValue(int fd){
        Log.d(MainActivity.TAG, "getValue() :: fd = " + fd);
        return getVal(fd);
    }

    private static native int setVal(int fd, int val);
    private static native int getVal(int fd);
    private static native int getFD(String name , int size);
}
