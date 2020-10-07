/**
 * Created on 16-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package archived.SEPT201908.multithreading;

public class ThreadJoinAndSync {

    private int count = 0;

    public static void main(String[] args) {
        ThreadJoinAndSync obj = new ThreadJoinAndSync();
        obj.doWork();
    }

    private synchronized void increment() {
        count++;
        System.out.println("tid=" + Thread.currentThread().getId() + ", count = " + count);
    }

    public void doWork() {
        Thread thread1 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 10000; i++) {
                    increment();
                }
            }
        });

        Thread thread2 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 10000; i++) {
                    increment();
                }
            }
        });

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("count = " + count);
    }
}
