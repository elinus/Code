package com.example.shmdemoandroidq;

public class SharedMemoryServerNativeLib {

    static {
        System.loadLibrary("native-lib");
    }

    public static native boolean createShm();
    public static native boolean releaseShm();
    public static native void setShmData(String data);
    public static native int getShmSize();
    public static native String getShmData();
    public static native int getShmFd();

}
