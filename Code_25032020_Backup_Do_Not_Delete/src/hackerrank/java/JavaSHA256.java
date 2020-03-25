package hackerrank.java;

import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class JavaSHA256 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String string = input.next();
        try {
            final MessageDigest messageDigest = MessageDigest.getInstance("SHA-256");
            messageDigest.reset();
            messageDigest.update(string.getBytes(StandardCharsets.UTF_8));
            final byte[] resultByte = messageDigest.digest();
            StringBuffer hexString = new StringBuffer();

            for (int i = 0; i < resultByte.length; i++) {
                String hex = Integer.toHexString(0xff & resultByte[i]);
                if(hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            System.out.println(hexString);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}
