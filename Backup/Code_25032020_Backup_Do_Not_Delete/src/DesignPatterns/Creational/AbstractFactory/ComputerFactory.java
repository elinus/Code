package DesignPatterns.Creational.AbstractFactory;

public class ComputerFactory {

    public static Computer getComputer(ComputerAbstractFactory factory) {
        return factory.createFactory();
    }
}
