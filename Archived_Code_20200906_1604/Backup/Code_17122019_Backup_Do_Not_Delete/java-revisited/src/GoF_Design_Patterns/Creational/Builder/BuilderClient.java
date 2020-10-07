package GoF_Design_Patterns.Creational.Builder;

public class BuilderClient {

    public static void main(String[] args) {

        HouseBuilder builder = new ConcreteHouseBuilder();
        HouseBuilderDirector director = new HouseBuilderDirector(builder);
        System.out.println("director.construct() = " + director.construct());
        
        builder = new WoodenHouseBuilder();
        director = new HouseBuilderDirector(builder);
        System.out.println("director.construct() = " + director.construct());
    }
}
