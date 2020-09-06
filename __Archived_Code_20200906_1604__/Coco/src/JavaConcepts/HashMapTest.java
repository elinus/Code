package JavaConcepts;

import java.util.*;

public class HashMapTest {

    public static void main(String[] args) {
        HashMap<Integer, String> empMap = new HashMap<>();
        empMap.put(1, "Emp-1");
        empMap.put(2, "Emp-2");
        empMap.put(3, "Emp-3");
        empMap.put(4, "Emp-4");
        System.out.println(empMap);
        System.out.println("empMap.isEmpty() = " + empMap.isEmpty());
        System.out.println(empMap.size());
        System.out.println("empMap.get(4) = " + empMap.get(4));
        System.out.println("empMap.get(5) = " + empMap.get(5));
        System.out.println("empMap.containsKey(1) = " + empMap.containsKey(1));
        System.out.println("empMap.containsValue(\"Emp-4\") = " + empMap.containsValue("Emp-4"));

        Set<Map.Entry<Integer, String>> entries = empMap.entrySet();
        System.out.println("entries = " + entries);
        Set<Integer> keys = empMap.keySet();
        System.out.println("keys = " + keys);
        Collection<String> values = empMap.values();
        System.out.println("values = " + values);

        Iterator<Map.Entry<Integer, String>> iterator = empMap.entrySet().iterator();
        while (iterator.hasNext()) {
            Map.Entry<Integer, String> next = iterator.next();
            System.out.println("next.getKey() = " + next.getKey());
            System.out.println("next.getValue() = " + next.getValue());
        }

        empMap.clear();
        System.out.println("empMap.isEmpty() = " + empMap.isEmpty());
    }
}
