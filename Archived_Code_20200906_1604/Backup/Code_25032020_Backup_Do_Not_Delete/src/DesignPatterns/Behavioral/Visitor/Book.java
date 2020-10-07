package DesignPatterns.Behavioral.Visitor;

public class Book implements ItemElement {

    private int price;
    private String isbnNumber;

    public Book(int price, String isbnNumber) {
        this.price = price;
        this.isbnNumber = isbnNumber;
    }

    public int getPrice() {
        return price;
    }

    public String getIsbnNumber() {
        return isbnNumber;
    }

    @Override
    public int accept(ShoppingCartVisitor visitor) {
        return visitor.visit(this);
    }

    @Override
    public String toString() {
        return "Book{" +
                "price=" + price +
                ", isbnNumber='" + isbnNumber + '\'' +
                '}';
    }
}
