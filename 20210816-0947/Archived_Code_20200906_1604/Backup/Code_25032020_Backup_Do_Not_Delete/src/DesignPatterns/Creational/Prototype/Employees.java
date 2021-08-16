package DesignPatterns.Creational.Prototype;

import java.util.ArrayList;
import java.util.List;

public class Employees implements Cloneable {
    private List<String> empList;
    public Employees() {
        empList = new ArrayList<>();
    }
    public Employees(List<String> list) {
        empList = list;
    }
    public void loadData() {
        empList.add("Emp-1");
        empList.add("Emp-2");
        empList.add("Emp-3");
        empList.add("Emp-4");
        empList.add("Emp-5");
    }
    public List<String> getEmpList() {
        return empList;
    }

    @Override
    protected Employees clone() throws CloneNotSupportedException {
        List<String> newEmp = new ArrayList<>();
        for (String s: empList) {
            newEmp.add(s);
        }
        return new Employees(newEmp);
    }
}
