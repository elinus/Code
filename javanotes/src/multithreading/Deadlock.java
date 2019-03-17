/**
 * Created on 17-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package multithreading;


import java.util.Random;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Deadlock {

    public static void main(String[] args) {
        final App9 app9 = new App9();
        Thread thread1 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    app9.firstThread();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread thread2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    app9.secondThread();
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

        app9.finished();
    }
}

class App9 {

    private Account account1 = new Account();
    private Account account2 = new Account();
    private Lock lock1 = new ReentrantLock();
    private Lock lock2 = new ReentrantLock();
    private void acquireLock(Lock lock1, Lock lock2) throws InterruptedException {
        while (true) {
            boolean firstLock = false;
            boolean secondLock = false;
            try {
                firstLock = lock1.tryLock();
                secondLock = lock2.tryLock();
            } finally {
                if(firstLock && secondLock) {
                    return;
                }
                if (firstLock) {
                    lock1.unlock();
                }
                if (secondLock) {
                    lock2.unlock();
                }
            }
            Thread.sleep(1);
        }
    }

    public void firstThread() throws InterruptedException {
        Random random = new Random();
        for (int i = 0; i < 10000; i++) {
//            lock1.lock();
//            lock2.lock();
            acquireLock(lock1, lock2);
            try {
                Account.transfer(account1, account2, random.nextInt(100));
            } finally {
                lock1.unlock();
                lock2.unlock();
            }
        }
    }

    public void secondThread() throws InterruptedException {
        Random random = new Random();
        for (int i = 0; i < 10000; i++) {
//            lock1.lock();
//            lock2.lock();
           acquireLock(lock2, lock1);
            try {
                Account.transfer(account2, account1, random.nextInt(100));
            } finally {
                lock1.unlock();
                lock2.unlock();
            }
        }
    }

    public void finished() {
        System.out.println("Account 1 balance = " + account1.getBalance());
        System.out.println("Account 2 balance = " + account2.getBalance());
        System.out.println("Total balance = " + (account1.getBalance() + account2.getBalance()));
    }
}
