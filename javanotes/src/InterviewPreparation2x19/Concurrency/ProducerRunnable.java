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

public class ProducerRunnable implements Runnable {

    private BlockingQueue queue = null;

    public ProducerRunnable(BlockingQueue queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            int value = new Random().nextInt(100);
            long sleep = new Random().nextInt(2000);

            try {
                System.out.println(Thread.currentThread().getName()
                        + ", queue = " + queue.toString()
                        + ", put value = " + value);
                queue.put(value); // Blocks

                // special value is returned = true/false
//                if (queue.offer(value)){
//                    System.out.println("offer value = " + value);
//                }

                // time out
//                queue.offer(value, 100, TimeUnit.MILLISECONDS);

                // throw exception
//                queue.add(value);
                /*
                * Exception in thread "Thread-1" java.lang.IllegalStateException: Queue full
                * */
                Thread.sleep(sleep);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
