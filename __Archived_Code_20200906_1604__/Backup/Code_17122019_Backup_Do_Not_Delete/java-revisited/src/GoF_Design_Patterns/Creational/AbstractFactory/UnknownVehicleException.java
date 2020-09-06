package GoF_Design_Patterns.Creational.AbstractFactory;

public class UnknownVehicleException extends Exception {

    UnknownVehicleException(String error_msg) {
        super(error_msg);
    }
}
