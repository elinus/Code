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

import java.util.Random;
import java.util.UUID;
import java.util.concurrent.BlockingQueue;

public class DelayedProducer {

    private BlockingQueue queue;
    private final Random random = new Random();

    public DelayedProducer(BlockingQueue queue) {
        this.queue = queue;
    }

    private Thread producer = new Thread(new Runnable() {
        @Override
        public void run() {
            while (true) {

                try {
                    int delay = random.nextInt(10000);
                    DelayObject object = new DelayObject(UUID.randomUUID().toString(), delay);
                    System.out.printf("Put object = %s%n", object);
                    queue.put(object);
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

            }
        }
    }, "Producer Thread");

    public void start () {
        producer.start();
    }
}
