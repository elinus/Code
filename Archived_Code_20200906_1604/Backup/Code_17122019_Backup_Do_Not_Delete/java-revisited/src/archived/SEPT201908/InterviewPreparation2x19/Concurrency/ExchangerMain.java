/**
 * Created on 30-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package archived.SEPT201908.InterviewPreparation2x19.Concurrency;

import java.util.concurrent.Exchanger;

public class ExchangerMain {
    public static void main(String[] args) {
        Exchanger exchanger = new Exchanger();
        ExchangerRunnable er1 = new ExchangerRunnable(exchanger, "Hello");
        ExchangerRunnable er2 = new ExchangerRunnable(exchanger, "World!");
        new Thread(er1).start();
        new Thread(er2).start();
    }
}
