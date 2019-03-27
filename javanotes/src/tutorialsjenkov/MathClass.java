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

package tutorialsjenkov;

import java.lang.*;

public class MathClass {
    public static void main(String[] args) {
        // Floating point precision
        double dVar = 0d;
        System.out.println("dVar = " + dVar);

        for (int i = 0; i < 100; i++) {
            dVar += 0.01d;
        }
        System.out.println("dVar = " + dVar);
        System.out.printf("dVar(.2f) = %.2f\n" , dVar);
        
        // Basic math functions
        System.out.println("Math.abs(-14) = " + Math.abs(-14));
        System.out.println("Math.abs(20) = " + Math.abs(20));
        System.out.println("Math.ceil(14.20) = " + Math.ceil(14.20));
        System.out.println("Math.floor(14.20) = " + Math.floor(14.20));
        System.out.println("Math.floorDiv(20, 14) = " + Math.floorDiv(20, 14));
        System.out.println("Math.min(14, 20) = " + Math.min(14, 20));
        System.out.println("Math.max(14, 20) = " + Math.max(14, 20));
        System.out.println("Math.round(23.445) = " + Math.round(23.445));
        System.out.println("Math.round(23.545) = " + Math.round(23.545));
//        System.out.println("Math.round(10.0) = " + Math.round(10.0));
        System.out.println("Math.exp(1.0) = " + Math.exp(1.0));
        System.out.println("Math.exp(2.0) = " + Math.exp(2.0));
        System.out.println("Math.log(1.0) = " + Math.log(1.0));
        System.out.println("Math.log(10) = " + Math.log(10));
        System.out.println("Math.log10(10.0) = " + Math.log10(10.0));
        System.out.println("Math.pow(2.0, 2.0) = " + Math.pow(2.0, 2.0));
        System.out.println("Math.sqrt(3.0) = " + Math.sqrt(3.0));
        System.out.println("Math.PI = " + Math.PI);
        System.out.println("Math.sin((Math.PI)) = " + Math.sin((Math.PI)));
        System.out.println("Math.cos((Math.PI)) = " + Math.cos((Math.PI)));
        System.out.println("Math.tan((Math.PI)) = " + Math.tan((Math.PI)));
        System.out.println("Math.toDegrees(Math.PI) = " + Math.toDegrees(Math.PI));
        System.out.println("Math.toRadians(Math.PI) = " + Math.toRadians(Math.PI));

        double asin = Math.asin(1.0);
        System.out.println("asin = " + asin);
        double acos = Math.acos(1.0);
        System.out.println("acos = " + acos);
        double atan = Math.atan(1.0);
        System.out.println("atan = " + atan);

        double sinh = Math.sinh(1.0);
        System.out.println("sinh = " + sinh);
        double cosh = Math.cosh(1.0);
        System.out.println("cosh = " + cosh);
        double tanh = Math.tanh(1.0);
        System.out.println("tanh = " + tanh);
    }
}
