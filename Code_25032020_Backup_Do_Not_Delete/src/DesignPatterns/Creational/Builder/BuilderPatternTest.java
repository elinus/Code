package DesignPatterns.Creational.Builder;

public class BuilderPatternTest {

    public static void main(String[] args) {
        Computer computer = new Computer.ComputerBuilder("1 TB", "8 GB")
                .setBluetoothEnabled(true)
                .setGraphicsCardEnabled(true).build();
        System.out.println(computer);
    }
}
