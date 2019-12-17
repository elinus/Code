package GoF_Design_Patterns.Creational.Builder;

public interface HouseBuilder {

    public HouseBuilder buildFloor();
    public HouseBuilder buildWall();
    public HouseBuilder buildRoof();
    public House build();
}
