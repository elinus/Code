package JavaConcepts;

public class Employee extends Person implements Comparable<Employee> {

    int id;
    double salary;

    public Employee(String name, int age, int id, double salary) {
        super(name, age);
        System.out.println("Parameterized Constructor for Employee!");
        this.id = id;
        this.salary = salary;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    @Override
    public String toString() {
        return super.toString() + ", Employee{" +
                "id=" + id +
                '}';
    }

    @Override
    public int compareTo(Employee employee) {
        return this.id > employee.id ? 0 : 1;
    }
}
