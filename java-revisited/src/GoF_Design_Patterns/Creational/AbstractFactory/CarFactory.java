package GoF_Design_Patterns.Creational.AbstractFactory;

public class CarFactory extends Factory {
    @Override
    public Engine getEngine() {
        return new CarEngine();
    }

    @Override
    public Tyre getTyre() {
        return new CarTyre();
    }
}
