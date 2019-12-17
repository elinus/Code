package GoF_Design_Patterns.Behavioral.TemplateMethod;

public class TemplateMethodClient {

    public static void main(String[] args) {
        System.out.println("----- CHEESE PIZZA -----");
        Pizza cheesePizza = new CheesePizza();
        cheesePizza.preparePizza();

        System.out.println("----- VEGAN PIZZA -----");
        Pizza veganPizza = new VeganPizza();
        veganPizza.preparePizza();
    }
}
