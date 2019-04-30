/**
 * Created on 18-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package multithreading;

import java.util.Random;

public class InterruptingThreads {
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Starting..");
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                Random random = new Random();
                for (int i = 0; i < 1E8; i++) {
                    if (Thread.currentThread().isInterrupted()) {
                        System.out.println("Interrupted!");
                        break;
                    }
                    Math.sin(random.nextDouble());
                }
            }
        });

        thread.start();
        Thread.sleep(500);
        thread.interrupt();
        thread.join();
        System.out.println("Finished!");
    }
}
