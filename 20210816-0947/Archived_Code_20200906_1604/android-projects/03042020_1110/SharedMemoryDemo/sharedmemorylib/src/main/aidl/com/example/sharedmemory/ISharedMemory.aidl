// ISharedMemory.aidl
package com.example.sharedmemory;

// Declare any non-default types here with import statements
import android.os.ParcelFileDescriptor;

interface ISharedMemory {

    ParcelFileDescriptor OpenSharedMem(String name, int size, boolean create);

}
