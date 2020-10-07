package DesignPatterns.Behavioral.TemplateMethod;

public class HousingClient {
    public static void main(String[] args) {
        HouseTemplate house = new WoodenHouse();
        house.buildHouse();

        System.out.println("\n");
        house = new GlassHouse();
        house.buildHouse();
    }
}
