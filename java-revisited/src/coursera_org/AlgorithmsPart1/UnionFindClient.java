package coursera_org.AlgorithmsPart1;

import java.util.Scanner;

public class UnionFindClient {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();

//        QuickFind qf = new QuickFind(N);
        QuickUnion qu = new QuickUnion(N);
        while (input.hasNext()) {
            int u = input.nextInt();
            int v = input.nextInt();
            if (!qu.connected(u, v)) {
                qu.union(u, v);
                System.out.println(u + " " + v);
            }
        }


    }
}
