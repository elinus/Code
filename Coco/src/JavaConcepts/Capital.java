package JavaConcepts;

public class Capital {
    String capitalName;
    long population;

    public Capital(String capitalName, long population) {
        this.capitalName = capitalName;
        this.population = population;
    }

    public Capital(Capital other) {
        this.capitalName = other.capitalName;
        this.population = other.population;
    }

    public String getCapitalName() {
        return capitalName;
    }

    public void setCapitalName(String capitalName) {
        this.capitalName = capitalName;
    }

    public long getPopulation() {
        return population;
    }

    public void setPopulation(long population) {
        this.population = population;
    }

    @Override
    public String toString() {
        return "Capital{" +
                "capitalName='" + capitalName + '\'' +
                ", population=" + population +
                '}';
    }
}
