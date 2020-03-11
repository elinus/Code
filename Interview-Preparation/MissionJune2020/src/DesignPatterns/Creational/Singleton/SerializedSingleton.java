package DesignPatterns.Creational.Singleton;

import java.io.Serializable;

public class SerializedSingleton implements Serializable {
    private SerializedSingleton(){}
    private static class SingletonHelper {
        private static final SerializedSingleton instance = new SerializedSingleton();
    }
    public static SerializedSingleton getInstance() {
        return SingletonHelper.instance;
    }
    protected Object readResolve() {
        return getInstance();
    }
}
