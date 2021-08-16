package JavaConcepts;

public class Country {
    String name;
    long population;
    Capital capital;

    public Country(String name, long population, Capital capital) {
        this.name = name;
        this.population = population;
        this.capital = capital;
    }

    public Country(Country other) {
        this.name = other.name;
        this.population = other.population;
        this.capital = new Capital(other.capital);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getPopulation() {
        return population;
    }

    public void setPopulation(long population) {
        this.population = population;
    }

    public Capital getCapital() {
        return capital;
    }

    public void setCapital(Capital capital) {
        this.capital = capital;
    }

    @Override
    public String toString() {
        return "Country{" +
                "name='" + name + '\'' +
                ", population=" + population +
                ", capital=" + capital +
                '}';
    }
}
