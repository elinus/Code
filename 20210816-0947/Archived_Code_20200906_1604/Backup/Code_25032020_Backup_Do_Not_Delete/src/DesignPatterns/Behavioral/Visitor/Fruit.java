package DesignPatterns.Behavioral.Visitor;

public class Fruit implements ItemElement {

    private String name;
    private int weight;
    private int pricePerKg;

    public Fruit(String name, int weight, int pricePerKg) {
        this.name = name;
        this.weight = weight;
        this.pricePerKg = pricePerKg;
    }

    public String getName() {
        return name;
    }

    public int getWeight() {
        return weight;
    }

    public int getPricePerKg() {
        return pricePerKg;
    }

    @Override
    public int accept(ShoppingCartVisitor visitor) {
        return visitor.visit(this);
    }

    @Override
    public String toString() {
        return "Fruit{" +
                "name='" + name + '\'' +
                ", weight=" + weight +
                ", pricePerKg=" + pricePerKg +
                '}';
    }
}
