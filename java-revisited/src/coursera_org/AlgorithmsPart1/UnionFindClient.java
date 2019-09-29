package coursera_org.AlgorithmsPart1;

import java.util.Scanner;

public class UnionFindClient {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        QuickFind qf = new QuickFind(N);
        while (input.hasNext()) {
            int u = input.nextInt();
            int v = input.nextInt();
            if (!qf.connected(u, v)) {
                qf.union(u, v);
                System.out.println(u + " " + v);
            }
        }
    }
}
