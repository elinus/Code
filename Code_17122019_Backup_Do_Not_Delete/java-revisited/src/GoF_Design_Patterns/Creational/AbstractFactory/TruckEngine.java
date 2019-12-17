package GoF_Design_Patterns.Creational.AbstractFactory;

public class TruckEngine implements Engine {
    @Override
    public void design() {
        System.out.println("TruckEngine.design");
    }

    @Override
    public void manufacture() {
        System.out.println("TruckEngine.manufacture");
    }

    @Override
    public void test() {
        System.out.println("TruckEngine.test");
    }
}
