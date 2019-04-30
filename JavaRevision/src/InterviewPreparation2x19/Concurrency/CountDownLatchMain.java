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

package InterviewPreparation2x19.Concurrency;

import java.util.concurrent.CountDownLatch;

public class CountDownLatchMain {
    public static void main(String[] args) {
        CountDownLatch latch = new CountDownLatch(5);
        WaiterRunnable waiterRunnable =
                new WaiterRunnable(latch);
        DecrementerRunnable decrementerRunnable =
                new DecrementerRunnable(latch);
        Thread t1 = new Thread(waiterRunnable, "Waiter");
        Thread t2 = new Thread(decrementerRunnable, "Decrement");
        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Exiting " + Thread.currentThread().getName() + " thread ..!");
    }
}
