// ISharedMemoryService.aidl
package com.example.sharedmemoryservice;

// Declare any non-default types here with import statements
import android.os.SharedMemory;

interface ISharedMemoryService {
    SharedMemory getShm(String name, int size);
    int getByteBufferDataLength();
}
