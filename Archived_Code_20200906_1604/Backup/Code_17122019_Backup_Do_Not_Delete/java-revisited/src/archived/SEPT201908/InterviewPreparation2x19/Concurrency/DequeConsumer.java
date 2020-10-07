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
import java.util.concurrent.BlockingDeque;

public class DequeConsumer {
    private final Random random = new Random();
    private BlockingDeque deque;
    private String name1;
    private String name2;

    public DequeConsumer(BlockingDeque deque, String name1, String name2) {
        this.deque = deque;
        this.name1 = name1;
        this.name2 = name2;
    }

    private Thread thread1 = new Thread(new Runnable() {
        @Override
        public void run() {
            for (int i = 0; i < 10; i++) {
                try {
                    Thread.sleep(random.nextInt(1000));
                    int value = (int) deque.takeFirst();
                    System.out.printf("[%s] - TakeFirst object = %s%n", Thread.currentThread().getName(), value);
                    printDeque();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    });

    private Thread thread2 = new Thread(new Runnable() {
        @Override
        public void run() {
            for (int i = 0; i < 10; i++) {
                try {
                    Thread.sleep(random.nextInt(1000));
                    int value = (int) deque.takeLast();
                    System.out.printf("[%s] - TakeLast object = %s%n", Thread.currentThread().getName(), value);
                    printDeque();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    });

    private void printDeque() {
        System.out.printf("[%s] Queue = %s%n", Thread.currentThread().getName(), deque.toString());
    }

    public void startConsumer() {
        thread1.setName(name1);
        thread2.setName(name2);
        thread1.start();
        thread2.start();
    }
}
