package hackerrank.java;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class JavaList {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        List<Integer> L = new LinkedList<Integer>();
        for (int i = 0; i < N; i++) {
            L.add(input.nextInt());
        }
        int Q = input.nextInt();
        String queryType = null;
        while (Q-- > 0) {
            queryType = input.next();
            if (queryType.equals("Insert")) {
                int x = input.nextInt();
                int y = input.nextInt();
                L.add(x, y);
            } else if (queryType.equals("Delete")) {
                int x = input.nextInt();
                L.remove(x);
            }
        }
        input.close();
        Iterator iterator = L.iterator();
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
    }
}
