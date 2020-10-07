package GoF_Design_Patterns.Creational.AbstractFactory;

public class TruckTyre implements Tyre {
    @Override
    public void design() {
        System.out.println("TruckTyre.design");
    }

    @Override
    public void manufacture() {
        System.out.println("TruckTyre.manufacture");
    }
}
