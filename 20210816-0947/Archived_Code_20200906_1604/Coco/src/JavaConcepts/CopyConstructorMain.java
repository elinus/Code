package JavaConcepts;

public class CopyConstructorMain {

    public static void main(String[] args) {

        Capital bangalore = new Capital("Bangalore", 1000);
        Country india = new Country("India", 100000, bangalore);
        Country new_india = new Country(india);

        System.out.println("India :: " + india);
        System.out.println("New India :: " + new_india);

        india.getCapital().setCapitalName("Unknown");

        System.out.println("India :: " + india);
        System.out.println("New India :: " + new_india);

    }
}
