package GoF_Design_Patterns.Creational.Builder;

public class House {

    private String floorType;
    private String wallType;
    private String roofType;

    public String getFloorType() {
        return floorType;
    }

    public void setFloorType(String floorType) {
        this.floorType = floorType;
    }

    public String getWallType() {
        return wallType;
    }

    public void setWallType(String wallType) {
        this.wallType = wallType;
    }

    public String getRoofType() {
        return roofType;
    }

    public void setRoofType(String roofType) {
        this.roofType = roofType;
    }

    @Override
    public String toString() {
        return "House{" +
                "floorType='" + floorType + '\'' +
                ", wallType='" + wallType + '\'' +
                ", roofType='" + roofType + '\'' +
                '}';
    }
}
