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

public class ExchangerRunnable implements Runnable {

    Exchanger exchanger = null;
    Object object = null;

    public ExchangerRunnable(Exchanger exchanger, Object object) {
        this.exchanger = exchanger;
        this.object = object;
    }

    @Override
    public void run() {
        try {
            Object previous = this.object;
            object = exchanger.exchange(object);
            System.out.println(Thread.currentThread().getName()
                    + " exchanged " + previous
                    + " for " + object);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
