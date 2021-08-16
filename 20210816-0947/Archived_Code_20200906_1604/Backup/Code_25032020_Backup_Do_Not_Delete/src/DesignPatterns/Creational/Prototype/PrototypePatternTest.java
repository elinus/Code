package DesignPatterns.Creational.Prototype;

public class PrototypePatternTest {

    public static void main(String[] args) {
        Employees employees = new Employees();
        employees.loadData();

        Employees employeesClone = null;
        try {
            employeesClone = employees.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }

        System.out.println("employees = " + employees.getEmpList());
        System.out.println("employees-clone = " + employeesClone.getEmpList());
    }
}
