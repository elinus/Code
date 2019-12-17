package GoF_Design_Patterns.Behavioral.TemplateMethod;

public abstract class Pizza {

    public final void preparePizza() {
        selectCrust();
        addIngredients();
        addToppings();
        cook();
    }

    protected abstract void addToppings();
    protected abstract void addIngredients();
    protected void selectCrust() {
        System.out.println("Pizza.selectCrust");
    }
    protected void cook() {
        System.out.println("Pizza.cook");
    }
}
