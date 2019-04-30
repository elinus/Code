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

import java.util.concurrent.BlockingQueue;

public class DelayedConsumer {
    private String name;
    private BlockingQueue queue;

    public DelayedConsumer(String name, BlockingQueue queue) {
        this.name = name;
        this.queue = queue;
    }

    private Thread consumer = new Thread(new Runnable() {
        @Override
        public void run() {
            while (true) {
                try {
                    DelayObject object = (DelayObject) queue.take();
                    System.out.printf("[%s] - Take object = %s%n", Thread.currentThread().getName(), object);
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    });

    public void start() {
        consumer.setName(name);
        consumer.start();
    }
}
