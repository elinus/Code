package GoF_Design_Patterns.Creational.AbstractFactory;

public class AbstractFactoryClient {

    public static void main(String[] args) {

        Factory factory = null;
        try {
            factory = Factory.getFactory("car");
            Engine engine = factory.getEngine();
            engine.design();
            engine.manufacture();
            engine.test();
            Tyre tyre = factory.getTyre();
            tyre.design();
            tyre.manufacture();
        } catch (UnknownVehicleException e) {
            e.printStackTrace();
        }
    }
}
