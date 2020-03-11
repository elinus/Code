package DesignPatterns.Creational.AbstractFactory;

import DesignPatterns.Creational.Factory.PC;

public class TestAbstractFactory {

    public static void main(String[] args) {
        Computer pc = ComputerFactory.getComputer(
                new PCFactory("8 GB", "1 TB", "Intel CORE i7"));
        Computer server = ComputerFactory.getComputer(
                new ServerFactory( "64 GB", "128 TB", "Intel CORE i9"));
        System.out.println("PC #=> " + pc);
        System.out.println("Server #=> " + server);
    }
}
