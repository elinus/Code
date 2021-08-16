package DesignPatterns.Behavioral.TemplateMethod;

public class WoodenHouse extends HouseTemplate {

    @Override
    public void buildWalls() {
        System.out.println("Building Wooden House");
    }

    @Override
    public void buildPillars() {
        System.out.println("Building Wooden Pillar");
    }
}
