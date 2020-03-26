package JavaConcepts;

public class Person {

    private String name;
    private int age;

    public Person() {
        System.out.println("Default Constructor for Person!");
        name = "default";
        age = 0;
    }

    public Person(String name, int age) {
        this();
        System.out.println("Parameterized Constructor for Person!");
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
