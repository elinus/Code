/**
 * Created on 29-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package InterviewPreparation2x19.Concurrency;

import java.util.Random;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class ConsumerRunnable implements Runnable {

    private BlockingQueue queue = null;

    public ConsumerRunnable(BlockingQueue queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            long sleep = new Random().nextInt(2000);
            try {

                int value = (int) queue.take(); // Blocks
                
                // special value is returned, true/false, Exception thrown = java.lang.NullPointerException
//                if (queue.peek() != null) {
//                    int value = (int) queue.poll();
//                    System.out.println("poll value = " + value);
//                }

                // time out, Exception thrown = NullPointerException
//                int value = (int) queue.poll(200, TimeUnit.MILLISECONDS);
                
                // throws exception
//                int value = (int) queue.remove();
                /*
                 * Exception in thread "Thread-0" java.util.NoSuchElementException
                 * */
                System.out.println(Thread.currentThread().getName()
                        + ", queue = " + queue.toString()
                        + ", take value = " + value);

                Thread.sleep(sleep);

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
