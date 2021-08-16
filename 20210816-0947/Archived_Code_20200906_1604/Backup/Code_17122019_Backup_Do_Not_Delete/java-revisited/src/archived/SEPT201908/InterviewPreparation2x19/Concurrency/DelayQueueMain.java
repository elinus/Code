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

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.DelayQueue;

public class DelayQueueMain {
    public static void main(String[] args) {
        BlockingQueue queue = new DelayQueue();
        new DelayedProducer(queue).start();
        new DelayedConsumer("Consumer Thread", queue).start();
    }
}
