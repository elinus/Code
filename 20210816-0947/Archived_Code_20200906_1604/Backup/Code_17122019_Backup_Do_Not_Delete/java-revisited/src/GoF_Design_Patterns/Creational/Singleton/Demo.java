package GoF_Design_Patterns.Creational.Singleton;

public class Demo {

    public static void main(String[] args) {
        Singleton obj1 = Singleton.getInstance();
        obj1.printObj();
        Singleton obj2 = Singleton.getInstance();
        obj2.printObj();
    }
}
