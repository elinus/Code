package com.elinus.serverserviceapp;

import android.os.RemoteException;

import com.elinus.simplemathlib.ISimpleMath;

public class SimpleMathServiceImpl extends ISimpleMath.Stub {

    @Override
    public int add(int a, int b) throws RemoteException {
        return a + b;
    }

    @Override
    public int sub(int a, int b) throws RemoteException {
        return a - b;
    }

}
