package hackerrank.java;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class JavaArrayList {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        List[] lines = new List[n];
        for (int i = 0; i < n; i++) {
            int d = input.nextInt();
            lines[i] = new ArrayList();
            for (int j = 0; j < d; j++) {
                int x = input.nextInt();
                lines[i].add(x);
            }
        }
        int q = input.nextInt();
        while (q > 0) {
            int x = input.nextInt();
            int y = input.nextInt();
            if (x >= 1 && x <= n && y >= 1 && y <= lines[x - 1].size()) {
                System.out.println(lines[x - 1].get(y - 1));
            } else {
                System.out.println("ERROR!");
            }
            q--;
        }
    }
}
