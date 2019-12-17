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

import java.util.concurrent.Semaphore;

public class SemaphoreExample {

    private Semaphore semaphore = new Semaphore(10);
    public void printLock() {
        try {
            semaphore.acquire();
            System.out.println("Locks acquired!");
            System.out.println("Locks remaining >> " + semaphore.availablePermits());
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            semaphore.release();
            System.out.println("Locks Released!!");
        }
    }

    public static void main(String[] args) {
        final SemaphoreExample semObj = new SemaphoreExample();
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                semObj.printLock();
            }
        });
        thread.start();
    }
}
