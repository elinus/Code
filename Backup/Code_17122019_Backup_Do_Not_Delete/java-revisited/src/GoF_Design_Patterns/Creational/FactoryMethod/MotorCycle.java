package GoF_Design_Patterns.Creational.FactoryMethod;

public class MotorCycle implements Vehicle {
    @Override
    public void design() {
        System.out.println("MotorCycle.design");
    }

    @Override
    public void manufacture() {
        System.out.println("MotorCycle.manufacture");
    }
}
