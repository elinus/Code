package GoF_Design_Patterns.Creational.AbstractFactory;

public class TruckFactory extends Factory {
    @Override
    public Engine getEngine() {
        return new TruckEngine();
    }

    @Override
    public Tyre getTyre() {
        return new TruckTyre();
    }
}
