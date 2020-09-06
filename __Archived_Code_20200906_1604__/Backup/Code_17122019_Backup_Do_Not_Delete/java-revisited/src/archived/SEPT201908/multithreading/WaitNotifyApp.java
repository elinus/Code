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

import java.util.Scanner;

public class WaitNotifyApp {

    public static void main(String[] args) {
        final App7 app7 = new App7();
        Thread thread1 = new Thread(new Runnable() {
            @Override
            public void run() {
                app7.produce();
            }
        });

        Thread thread2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    app7.consumer();
                } catch (InterruptedException e) {
                    e.printStackTrace();
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
    }
}

class App7 {

    public void produce() {
        synchronized (this) {
            System.out.println("[tid=" + Thread.currentThread().getId() + "] Producer thread running...");
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("[tid=" + Thread.currentThread().getId() + "] Resumed!");
        }
    }

    public void consumer() throws InterruptedException {
        Scanner scanner = new Scanner(System.in);
        Thread.sleep(5000);
        synchronized (this) {
            System.out.println("[tid=" + Thread.currentThread().getId() + "] Press <ENTER> to continue.");
            scanner.nextLine();
            System.out.println("[tid=" + Thread.currentThread().getId() + "] <ENTER> key pressed.");
            notify();
            Thread.sleep(5000);
            System.out.println("[tid=" + Thread.currentThread().getId() + "] Done!");
        }
    }
}
