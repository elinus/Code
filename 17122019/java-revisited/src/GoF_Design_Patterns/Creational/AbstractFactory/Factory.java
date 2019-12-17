package GoF_Design_Patterns.Creational.AbstractFactory;

public abstract class Factory {

    private static Factory carFactory = null;
    private static Factory truckFactory = null;

    public abstract Engine getEngine();
    public abstract Tyre getTyre();

    public static Factory getFactory(String type) throws UnknownVehicleException {
        Factory factory = null;
        type = type.toLowerCase();
        switch (type) {
            case "car":
                if (carFactory == null)
                    carFactory = new CarFactory();
                factory = carFactory;
                break;
            case "truck":
                if (truckFactory == null)
                    truckFactory = new TruckFactory();
                factory = truckFactory;
                break;
            default:
                throw new UnknownVehicleException("Unknown vehicle type!");
        }
        return factory;
    }
}
