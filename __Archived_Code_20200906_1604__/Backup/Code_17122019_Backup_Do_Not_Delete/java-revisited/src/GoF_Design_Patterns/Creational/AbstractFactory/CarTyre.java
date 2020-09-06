package GoF_Design_Patterns.Creational.AbstractFactory;

public class CarTyre implements Tyre {
    @Override
    public void design() {
        System.out.println("CarTyre.design");
    }

    @Override
    public void manufacture() {
        System.out.println("CarTyre.manufacture");
    }
}
