package GoF_Design_Patterns.Behavioral.TemplateMethod;

public class CheesePizza extends Pizza {
    @Override
    protected void addToppings() {
        System.out.println("CheesePizza.addToppings");
    }

    @Override
    protected void addIngredients() {
        System.out.println("CheesePizza.addIngredients");
    }
}
