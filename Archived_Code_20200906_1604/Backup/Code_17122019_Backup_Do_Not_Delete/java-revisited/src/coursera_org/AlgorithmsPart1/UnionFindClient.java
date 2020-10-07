package coursera_org.AlgorithmsPart1;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

import java.util.Scanner;

public class UnionFindClient {

    public static void main(String[] args) {
//        Scanner input = new Scanner(System.in);
//        int N = input.nextInt();
        int N = StdIn.readInt();

//        QuickFind qf = new QuickFind(N);
        QuickUnion qu = new QuickUnion(N);
        while (!StdIn.isEmpty()) {
//        while (input.hasNext()) {
//            int u = input.nextInt();
            int u = StdIn.readInt();
//            int v = input.nextInt();
            int v = StdIn.readInt();
            if (!qu.connected(u, v)) {
                qu.union(u, v);
//                System.out.println(u + " " + v);
                StdOut.println(u + " " + v);
            }
        }
    }
}
