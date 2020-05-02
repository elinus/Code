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

package archived.SEPT201908.InterviewPreparation2x19;

public class DataTypes {

    public static void main(String[] args) {
        // Data types with their min/max values
        System.out.println("Boolean.FALSE = " + Boolean.FALSE);
        System.out.println("Boolean.TRUE = " + Boolean.TRUE);
        System.out.println("Byte.MIN_VALUE = " + Byte.MIN_VALUE);
        System.out.println("Byte.MAX_VALUE = " + Byte.MAX_VALUE);
        System.out.println("Character.MIN_VALUE = " + Character.MIN_VALUE);
        System.out.println("Character.MAX_VALUE = " + Character.MAX_VALUE);
        System.out.println("Integer.MIN_VALUE = " + Integer.MIN_VALUE);
        System.out.println("Integer.MAX_VALUE = " + Integer.MAX_VALUE);
        System.out.println("Short.MIN_VALUE = " + Short.MIN_VALUE);
        System.out.println("Short.MAX_VALUE = " + Short.MAX_VALUE);
        System.out.println("Long.MIN_VALUE = " + Long.MIN_VALUE);
        System.out.println("Long.MAX_VALUE = " + Long.MAX_VALUE);
        System.out.println("Float.MIN_VALUE = " + Float.MIN_VALUE);
        System.out.println("Float.MAX_VALUE = " + Float.MAX_VALUE);
        System.out.println("Double.MIN_VALUE = " + Double.MIN_VALUE);
        System.out.println("Double.MAX_VALUE = " + Double.MAX_VALUE);

        // Auto boxing
        Integer integer = new Integer(14);
        int i = integer.intValue();
        System.out.println("i = " + i);
        
        int ii = integer;
        System.out.println("ii = " + ii);

        // Exception in thread "main" java.lang.NullPointerException
        Integer integer1 = null;
        if (integer1 != null) {
            int iii = integer1;
        }
    }
}
