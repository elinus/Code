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

import java.util.Random;
import java.util.concurrent.CountDownLatch;

public class WaiterRunnable implements Runnable {

    private Random random = new Random();
    private CountDownLatch latch;

    public WaiterRunnable(CountDownLatch latch) {
        this.latch = latch;
    }

    @Override
    public void run() {
        try {
            latch.await();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("[" + Thread.currentThread().getName() + "] Waiter released!");
    }
}
