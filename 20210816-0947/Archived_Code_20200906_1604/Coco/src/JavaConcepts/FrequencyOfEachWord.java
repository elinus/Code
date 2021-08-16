package JavaConcepts;

import java.util.HashMap;

public class FrequencyOfEachWord {

    public static void main(String[] args) {
        String hello = "Hello World";
        HashMap<Character, Integer> hm = new HashMap<>();
        for (int i = 0; i < hello.length(); i++) {
            Character ch = hello.charAt(i);
            hm.computeIfPresent(ch, ((character, integer) -> integer+1));
            hm.computeIfAbsent(ch, ((character) -> 1));
        }
        System.out.println(hm);
    }
}
