package hackerrank.java;

import java.math.BigInteger;
import java.util.Scanner;

public class JavaBigInteger {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        BigInteger bi_n1 = new BigInteger(input.next());
        BigInteger bi_n2 = new BigInteger(input.next());
        System.out.println(bi_n1.add(bi_n2));
        System.out.println(bi_n1.multiply(bi_n2));
        if (bi_n1.isProbablePrime(100))
            System.out.println("Prime");
    }
}
