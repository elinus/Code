/**
 * Created on 27-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package InterviewPreparation2x19;

import java.util.Arrays;
import java.util.Comparator;

public class Array {
    public static void main(String[] args) {
        String[] strArr = new String[10];
        String[] strings = {"one", "two", "three"};
        int[] intArr = new int[]{1, 2, 3, 4, 5};

        System.out.println("Arrays.toString(intArr) = " + Arrays.toString(intArr));
        System.out.println("strings = " + strings.length);
        for (String x: strings) {
            System.out.println(x);
        }

        int[][] intArray = new int[10][20];
        for(int i=0; i < intArray.length; i++){
            for(int j=0; j < intArray[i].length; j++){
//                System.out.println("i: " + i + ", j: " + j);
            }
        }

        int[] source = new int[10];
        for(int i=0; i < source.length; i++) {
            source[i] = i;
        }
        int[] dest  = Arrays.copyOf(source, source.length);
        System.out.println("Arrays.toString(dest) = " + Arrays.toString(dest));


        int[]   ints = new int[10];
        for(int i=0; i < ints.length; i++){
            ints[i] = 10 - i;
        }
        int index = Arrays.binarySearch(ints, 6); // Binary search
        System.out.println(index);

        System.out.println(java.util.Arrays.toString(ints));
        Arrays.sort(ints);
        System.out.println(java.util.Arrays.toString(ints));

        Employee[] employeeArray = new Employee[3];
        employeeArray[0] = new Employee("Xander", 1);
        employeeArray[1] = new Employee("John"  , 3);
        employeeArray[2] = new Employee("Anna"  , 2);
        Arrays.sort(employeeArray, new Comparator<Employee>() {
            @Override
            public int compare(Employee o1, Employee o2) {
                int nameDiff = o1.name.compareTo(o2.name);
                if (nameDiff != 0)
                    return nameDiff;
                return o1.employeeId - o2.employeeId;
            }
        });

        for(int i=0; i < employeeArray.length; i++) {
            System.out.println(employeeArray[i].name);
        }

        int[] ints1 = {0,2,4,6,8,10};
        int[] ints2 = {0,2,4,6,8,10};
        int[] ints3 = {10,8,6,4,2,0};

        boolean ints1EqualsInts2 = Arrays.equals(ints1, ints2);
        boolean ints1EqualsInts3 = Arrays.equals(ints1, ints3);

        System.out.println(ints1EqualsInts2);
        System.out.println(ints1EqualsInts3);

        int[] intArray123 = new int[10];
        Arrays.fill(intArray123, 123);
        System.out.println(Arrays.toString(intArray123));
    }

    private static class Employee {
        public String name;
        public int    employeeId;

        public Employee(String name, int employeeId){
            this.name       = name;
            this.employeeId = employeeId;
        }
    }
}
