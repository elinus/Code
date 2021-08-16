package DesignPatterns.Behavioral.Visitor;

public class ShoppingCartClient {

    private static int calculatePrice(ItemElement[] itemElements) {
        ShoppingCartVisitor visitor = new ShoppingCartVisitorImpl();
        int sum = 0;
        for (ItemElement itemElement: itemElements) {
            sum += itemElement.accept(visitor);
        }
        return sum;
    }

    public static void main(String[] args) {
        ItemElement[] items = new ItemElement[] {
                new Book(20, "1234"),
                new Book(100, "5678"),
                new Fruit("Banana", 2, 100),
                new Fruit("Apple", 2, 200)
        };
        int total = calculatePrice(items);
        System.out.println("Total Cost = " + total);
    }
}
