package coco;

import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5 {
    public static String getMD5(String input) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] message_digest = md.digest(input.getBytes());
            BigInteger num = new BigInteger(1, message_digest);
            String hash_text = num.toString(16);
            while (hash_text.length() < 32) {
                hash_text = "0" + hash_text;
            }
            return hash_text;
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return "";
    }

    public static void main(String[] args) {
        String url = "https://www.educative.io/courses/grokking-the-system-design-interview/m2yDVZnQ8lG";
        System.out.println("url = " + url + "\nhash = " + MD5.getMD5(url));
    }
}
