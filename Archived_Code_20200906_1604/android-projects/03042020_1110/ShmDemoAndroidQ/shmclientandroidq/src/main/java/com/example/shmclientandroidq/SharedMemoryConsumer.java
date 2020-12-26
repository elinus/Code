package com.example.shmclientandroidq;

import android.os.SharedMemory;
import android.system.ErrnoException;
import android.system.OsConstants;
import android.util.Log;

import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;

public class SharedMemoryConsumer {

    public static final String TAG = MainActivity.TAG + "::Consumer";
    public static int BYTE_BUFFER_DATA_LENGTH = 0;

    private static ByteBuffer buffer = null;

    public static boolean mapShm(SharedMemory shm_instance, int size) {
        try {
            // Java OD Shared Memory Mapping Call
            buffer = shm_instance.map(OsConstants.PROT_READ | OsConstants.PROT_WRITE,
                    0, size);
            if (buffer != null) {
                Log.d( TAG, "Shm & buffer mapping success. "
                        + ":: buff. = " + buffer.toString()
                        + ", hash = " + buffer.hashCode());
            } else {
                Log.e(TAG, "error: shm & buffer mapping failed");
                return false;
            }
        } catch (ErrnoException e) {
            e.printStackTrace();
        }
        // Native Mapping Call
        if (!SharedMemoryClientNativeLib.mapSharedMemory(shm_instance, -1, size)){
            return false;
        }

        BYTE_BUFFER_DATA_LENGTH = size;
        return true;
    }

    public static void setShmData(String data) {
        try {
            buffer = ByteBuffer.wrap(data.getBytes("UTF-8"));
            Log.d(TAG, "set => data = " + data
                    + ", buffer = " + buffer.toString());
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    public static String getShmData() {
        String str = "";
        try {
            Log.d(TAG, "get => buffer remaining = " + buffer.remaining());
            byte[] bytes = new byte[BYTE_BUFFER_DATA_LENGTH];
            buffer.get(bytes);
            str = new String(bytes, "UTF-8");
            buffer.position(0);

            Log.d(TAG, "get => buffer = " + buffer.toString()
                    + ", str = " + str);
            return str;
        } catch (UnsupportedOperationException | UnsupportedEncodingException e) {
            str = e.toString();
        }
        return str;
    }
}
