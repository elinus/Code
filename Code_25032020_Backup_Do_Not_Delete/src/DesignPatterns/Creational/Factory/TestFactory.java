package DesignPatterns.Creational.Factory;

public class TestFactory {

    public static void main(String[] args) {
        Computer pc = ComputerFactory.getComputer("pc", "8 GB", "1 TB", "Intel CORE i7");
        Computer server = ComputerFactory.getComputer("server", "64 GB", "128 TB", "Intel CORE i9");
        System.out.println("PC #=> " + pc);
        System.out.println("Server #=> " + server);
    }
}
