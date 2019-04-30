/**
 * Created on 07-Apr-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package random_dev.Dev20190407;

public class CurrencyConverter {
    double rupee = 63;
    double dirham = 3; // UAE
    double real = 3;  // brazilian
    double chilean_peso = 595;
    double mexican_peso = 18;
    double _yen = 107;
    double $australian = 2;  // australian dollar
    double dollar;
    double Rupee = 63;
    double[] exchangeRates = new double[]{rupee, dirham, real, chilean_peso, mexican_peso,
        _yen, $australian, dollar, Rupee};

    void printCurrencies() {
//        System.out.println("rupee: " + rupee);
//        System.out.println("$australian: " + $australian);
//        System.out.println("dirham: " + dirham);
//        System.out.println("real: " + real);
//        System.out.println("chilean_peso: " + chilean_peso);
//        System.out.println("mexican_peso: " + mexican_peso);
//        System.out.println("_yen: " + _yen);
//        System.out.println("dollar: " + dollar);
        System.out.println("Rupee: " + exchangeRates[0]);
        System.out.println("rupee: " + exchangeRates[1]);
        System.out.println("$australian: " + exchangeRates[2]);
        System.out.println("dirham: " + exchangeRates[3]);
        System.out.println("real: " + exchangeRates[4]);
        System.out.println("chilean_peso: " + exchangeRates[5]);
        System.out.println("mexican_peso: " + exchangeRates[6]);
        System.out.println("_yen: " + exchangeRates[7]);
        System.out.println("dollar: " + exchangeRates[8]);
        System.out.println("Rupee: " + exchangeRates[exchangeRates.length-1]);
    }

    public static void main(String[] args) {
        CurrencyConverter cc = new CurrencyConverter();
        cc.printCurrencies();
    }
}
