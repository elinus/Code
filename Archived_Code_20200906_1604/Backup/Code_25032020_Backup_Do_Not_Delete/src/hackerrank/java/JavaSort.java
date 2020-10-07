package hackerrank.java;

import java.util.*;

public class JavaSort {

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int testCases = Integer.parseInt(in.nextLine());

        List<Student> studentList = new ArrayList<Student>();

        while(testCases > 0){
            int id = in.nextInt();
            String fname = in.next();
            double cgpa = in.nextDouble();

            Student st = new Student(id, fname, cgpa);
            studentList.add(st);

            testCases--;
        }

        Comparator StudentComparator = new  Comparator<Student>() {
            @Override
            public int compare(Student s1, Student s2) {
                if (s1.getCgpa() != s2.getCgpa())
                    return Double.compare(s2.getCgpa(), s1.getCgpa());
                else if (!s1.getFname().equals(s2.getFname()))
                    return s1.getFname().compareTo(s2.getFname());
                return s2.getId() - s1.getId();
            }
        };

        Collections.sort(studentList, StudentComparator);

        for(Student st: studentList){
            System.out.println(st.getFname());
        }
    }
}


class Student {

    private int id;
    private String fname;
    private double cgpa;
    public Student(int id, String fname, double cgpa) {
        super();
        this.id = id;
        this.fname = fname;
        this.cgpa = cgpa;
    }
    public int getId() {
        return id;
    }
    public String getFname() {
        return fname;
    }
    public double getCgpa() {
        return cgpa;
    }
}
