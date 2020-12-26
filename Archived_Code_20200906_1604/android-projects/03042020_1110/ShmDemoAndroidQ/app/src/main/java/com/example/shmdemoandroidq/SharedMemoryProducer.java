package com.example.shmdemoandroidq;

import android.os.SharedMemory;
import android.system.ErrnoException;
import android.system.OsConstants;
import android.util.Log;

import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;

public class SharedMemoryProducer {

    public static final String TAG = MainActivity.TAG + "::Producer";
    public static int BYTE_BUFFER_DATA_LENGTH = 0;
    private static SharedMemory shm_instance = null;
    private static ByteBuffer buffer = null;
    private static String shm_name = null;
    private static int shm_size = 0;

    public static SharedMemory createShm(String name, int size) {
        if (shm_instance != null) return shm_instance;
        try {
            shm_instance = SharedMemory.create(name, size);
            if (shm_instance != null) {
                buffer = shm_instance.map(OsConstants.PROT_READ | OsConstants.PROT_WRITE,
                        0, size);
                if (buffer != null) {
                    Log.d(TAG, "Shm & buffer mapping success. "
                            + ":: buf. = " + buffer.toString()
                            + ", hash = " + buffer.hashCode());
                    Log.d(TAG, String.valueOf(shm_instance.describeContents()));
                } else {
                    shm_instance = null;
                    Log.e(TAG, "Error: Shm & buffer mapping failed");
                }
            }
        } catch (ErrnoException e) {
            shm_instance = null;
            buffer = null;
            e.printStackTrace();
        }

        shm_name = name;
        shm_size = size;
        return shm_instance;
    }

    public static boolean releaseShm() {
        if (shm_instance != null && buffer != null) {
            SharedMemory.unmap(buffer);
            shm_instance.close();
            shm_instance = null;
            Log.d(TAG, "shm & buffer release success");
            return true;
        }
        return false;
    }

    public static void setShmData(String data) {
        buffer.position(0);
        buffer.put(data.getBytes(), 0, data.length());
        Log.d(TAG, "set => data = " + data
                + ", buf. = " + buffer.toString());
        BYTE_BUFFER_DATA_LENGTH = buffer.position();
//        Data buffer_data = new Data(buffer.position(), buffer.limit(), buffer.capacity());
    }

    public static String getShmData() {
        try {
            String str = new String(buffer.array(), "UTF-8");
            Log.d(TAG, "get => buf. = " + buffer.toString()
                    + ", str = " + str);
            return str;
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return null;
    }

    public static SharedMemory getShm() {
        return shm_instance;
    }

    public static int getShmSize() {
        return shm_size;
    }

    public static String getShmName() {
        return shm_name;
    }

    public static int getShmOffset() {
        return 0;
    }
}
