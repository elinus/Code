package GoF_Design_Patterns.Creational.FactoryMethod;

public class Car implements Vehicle {
    @Override
    public void design() {
        System.out.println("Car.design");
    }

    @Override
    public void manufacture() {
        System.out.println("Car.manufacture");
    }
}
