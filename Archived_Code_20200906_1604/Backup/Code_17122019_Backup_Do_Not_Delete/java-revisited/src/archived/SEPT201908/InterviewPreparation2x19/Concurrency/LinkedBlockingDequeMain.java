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

import java.util.concurrent.BlockingDeque;
import java.util.concurrent.LinkedBlockingDeque;

public class LinkedBlockingDequeMain {
    public static void main(String[] args) {
        BlockingDeque deque = new LinkedBlockingDeque(5);
        DequeConsumer consumer =
                new DequeConsumer(deque, "Consumer-1", "Consumer-2");
        DequeProducer producer =
                new DequeProducer(deque, "Producer-1", "Producer-2");
        consumer.startConsumer();
        producer.startProducer();

        System.out.println("exiting .." + Thread.currentThread().getName() + " thread ..!");
    }
}
