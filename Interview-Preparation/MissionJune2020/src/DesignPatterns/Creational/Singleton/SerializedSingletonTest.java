package DesignPatterns.Creational.Singleton;

import java.io.*;

public class SerializedSingletonTest {
    public static void main(String[] args) {
        SerializedSingleton singletonOne = SerializedSingleton.getInstance();
        try {
            ObjectOutput output = new ObjectOutputStream(new FileOutputStream("SingletonObj.ser"));
            output.writeObject(singletonOne);
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        SerializedSingleton singletonTwo = null;
        try {
            ObjectInput input = new ObjectInputStream(new FileInputStream("SingletonObj.ser"));
            singletonTwo = (SerializedSingleton) input.readObject();
            input.close();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        System.out.println("singletonOne.hashCode() = " + singletonOne.hashCode());
        System.out.println("singletonTwo.hashCode() = " + singletonTwo.hashCode());
    }
}
