/**
 * Created on 27-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package InterviewPreparation2x19;

import java.nio.charset.Charset;
import java.util.Arrays;

public class StringClass {
    public static void main(String[] args) {
        String string = "Good day!";
        byte[] bytes1 = string.getBytes();
        System.out.println("Arrays.toString(bytes1) = " + Arrays.toString(bytes1));

        byte[] bytes2 = string.getBytes(Charset.forName("UTF-8"));
        System.out.println("Arrays.toString(bytes2) = " + Arrays.toString(bytes2));
    }
}
