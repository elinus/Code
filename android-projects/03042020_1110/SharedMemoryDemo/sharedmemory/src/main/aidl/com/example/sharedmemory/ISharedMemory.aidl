// ISharedMemory.aidl
package com.example.sharedmemory;

// Declare any non-default types here with import statements
import android.os.ParcelFileDescriptor;

interface ISharedMemory {

    ParcelFileDescriptor OpenSharedMem(String name, int size, boolean create);

    /**
     * Demonstrates some basic types that you can use as parameters
     * and return values in AIDL.
     */
//    void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat,
//            double aDouble, String aString);
}
