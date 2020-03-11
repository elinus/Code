package DesignPatterns.Behavioral.Visitor;

public interface ItemElement {
    public int accept(ShoppingCartVisitor visitor);
}
