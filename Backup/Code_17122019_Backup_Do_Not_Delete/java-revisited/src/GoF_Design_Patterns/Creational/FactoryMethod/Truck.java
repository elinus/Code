package GoF_Design_Patterns.Creational.FactoryMethod;

public class Truck implements Vehicle {
    @Override
    public void design() {
        System.out.println("Truck.design");
    }

    @Override
    public void manufacture() {
        System.out.println("Truck.manufacture");
    }
}
