package GoF_Design_Patterns.Creational.Singleton;

public class Singleton {

    private static Singleton sInstance = null;

    private Singleton() {}

    public static Singleton getInstance() {
        if (sInstance == null) {
            synchronized (Singleton.class) {
                if (sInstance == null) {
                    sInstance = new Singleton();
                }
            }
        }
        return sInstance;
    }

    public void printObj() {
        System.out.println("Unique Id of the obj.: " + System.identityHashCode(this));
    }
}
