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

public class DecrementerRunnable implements Runnable {

    private Random random = new Random();
    private CountDownLatch latch;

    public DecrementerRunnable(CountDownLatch latch) {
        this.latch = latch;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            try {
                Thread.sleep(random.nextInt(1000));
                latch.countDown();
                System.out.println("[" + Thread.currentThread().getName() + "] " + latch.getCount());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
