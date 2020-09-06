package GoF_Design_Patterns.Behavioral.TemplateMethod;

public class VeganPizza extends Pizza {
    @Override
    protected void addToppings() {
        System.out.println("VeganPizza.addToppings");
    }

    @Override
    protected void addIngredients() {
        System.out.println("VeganPizza.addIngredients");
    }
}
