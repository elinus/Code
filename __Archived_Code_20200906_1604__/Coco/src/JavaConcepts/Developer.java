package JavaConcepts;

public class Developer extends Employee {

    int level;

    public Developer(String name, int age, int id, double salary) {
        super(name, age, id, salary);
    }

    @Override
    public double getSalary() {
        return salary;
    }

    public static void main(String[] args) {
        Employee e1 = new Developer("mourys", 32, 10001, 1000000.00);
        System.out.println(e1);
        System.out.println(e1.getSalary());
    }

}
