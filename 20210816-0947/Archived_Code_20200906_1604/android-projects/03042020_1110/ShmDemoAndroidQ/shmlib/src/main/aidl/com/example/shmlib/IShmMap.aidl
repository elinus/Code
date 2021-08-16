// IShmMap.aidl
package com.example.shmlib;

// Declare any non-default types here with import statements
import android.os.ParcelFileDescriptor;

interface IShmMap {

    ParcelFileDescriptor getShmFd();
    int getShmSize();
}
