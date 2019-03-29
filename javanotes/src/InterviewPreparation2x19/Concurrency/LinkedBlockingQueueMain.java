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

import java.util.concurrent.BlockingQueue;

import java.util.concurrent.LinkedBlockingQueue;

public class LinkedBlockingQueueMain {
    public static void main(String[] args) {
//        BlockingQueue queue = new LinkedBlockingQueue(); // bound = Integer.MAX_VALUE
        BlockingQueue boundedQueue  = new LinkedBlockingQueue(5);
        ConsumerRunnable consumerRunnable = new ConsumerRunnable(boundedQueue);
        ProducerRunnable producerRunnable = new ProducerRunnable(boundedQueue);
        Thread t1 = new Thread(consumerRunnable);
        Thread t2 = new Thread(producerRunnable);
        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("exiting " + Thread.currentThread().getName() + " ..!");
    }
}
