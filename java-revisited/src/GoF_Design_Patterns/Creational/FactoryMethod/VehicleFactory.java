package GoF_Design_Patterns.Creational.FactoryMethod;

public class VehicleFactory {

    VehicleFactory() {}

    public Vehicle getVehicle(String type) throws VehicleTypeNotFoundException {
        Vehicle vehicle = null;
        type = type.toLowerCase();
        switch (type) {
            case "car":
                vehicle = new Car();
                break;
            case "truck":
                vehicle = new Truck();
                break;
            case "motorcycle":
                vehicle = new MotorCycle();
                break;
            default:
                throw new VehicleTypeNotFoundException("Vehicle type not found exception!");
        }
        return vehicle;
    }
}
