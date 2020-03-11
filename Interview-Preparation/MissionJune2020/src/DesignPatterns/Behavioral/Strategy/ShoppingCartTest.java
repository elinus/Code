package DesignPatterns.Behavioral.Strategy;

public class ShoppingCartTest {

    public static void main(String[] args) {
        ShoppingCart cart = new ShoppingCart();
        Item item1 = new Item("1234", 1409);
        Item item2 = new Item("5678", 2003);
        cart.addItem(item1);
        cart.addItem(item2);
        cart.pay(new UpiStrategy("qwerty@pay", "9988776655"));
        cart.pay(new CreditCardStrategy("X-Bank", "123-4567-890", "987", "30-06-2020"));
    }
}
