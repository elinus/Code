package DesignPatterns.Behavioral.TemplateMethod;

public abstract class HouseTemplate {
    private void buildWindows() {
        System.out.println("Building Glass Windows");
    }
    private void buildFoundation() {
        System.out.println("Building Foundation");
    }
    public abstract void buildWalls();
    public abstract void buildPillars();
    public final void buildHouse() {
        buildFoundation();
        buildPillars();
        buildWalls();
        buildWindows();
        System.out.println("House is built!");
    }
}
