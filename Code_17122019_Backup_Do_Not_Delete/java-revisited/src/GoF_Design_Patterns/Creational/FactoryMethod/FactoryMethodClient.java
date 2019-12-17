package GoF_Design_Patterns.Creational.FactoryMethod;

public class FactoryMethodClient {

    public static void main(String[] args) {

        VehicleFactory vehicleFactory = new VehicleFactory();
        try {
            Vehicle car = vehicleFactory.getVehicle("car");
            if (car != null) {
                car.design();
                car.manufacture();
            }
        } catch (VehicleTypeNotFoundException e) {
            e.printStackTrace();
        }

        try {
            Vehicle bicycle = vehicleFactory.getVehicle("bicycle");
            if (bicycle != null) {
                bicycle.design();
                bicycle.manufacture();
            }
        } catch (VehicleTypeNotFoundException e) {
            e.printStackTrace();
        }
    }
}
