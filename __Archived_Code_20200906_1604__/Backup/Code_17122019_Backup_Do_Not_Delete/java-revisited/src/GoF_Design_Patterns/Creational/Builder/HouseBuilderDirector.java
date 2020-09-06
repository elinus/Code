package GoF_Design_Patterns.Creational.Builder;

public class HouseBuilderDirector {

    private HouseBuilder houseBuilder;

    public HouseBuilderDirector(HouseBuilder houseBuilder) {
        this.houseBuilder = houseBuilder;
    }

    public House construct() {
        return houseBuilder.buildFloor().buildWall().buildRoof().build();
    }
}
