package GoF_Design_Patterns.Creational.AbstractFactory;

public class CarEngine implements Engine {
    @Override
    public void design() {
        System.out.println("CarEngine.design");
    }

    @Override
    public void manufacture() {
        System.out.println("CarEngine.manufacture");
    }

    @Override
    public void test() {
        System.out.println("CarEngine.test");
    }
}
