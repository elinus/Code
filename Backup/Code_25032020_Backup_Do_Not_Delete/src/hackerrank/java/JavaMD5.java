package hackerrank.java;

import java.math.BigInteger;
import java.nio.charset.Charset;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.*;

public class JavaMD5 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String string = input.next();
        try {
            final MessageDigest messageDigest = MessageDigest.getInstance("MD5");
            messageDigest.reset();
            messageDigest.update(string.getBytes(Charset.forName("UTF8")));
            final byte[] resultByte = messageDigest.digest();
            BigInteger no = new BigInteger(1, resultByte);
            String result = no.toString(16);
            while (result.length() < 32) {
                result = "0" + result;
            }
            System.out.println(result);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}
