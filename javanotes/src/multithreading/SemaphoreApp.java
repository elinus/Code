/**
 * Created on 18-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package multithreading;

import java.util.concurrent.*;

public class SemaphoreApp {
    public static void main(String[] args) {

        ExecutorService service = Executors.newCachedThreadPool();
        for (int i = 0; i < 200; i++) {
            service.submit(new Runnable() {
                @Override
                public void run() {
                    Connection.getInstance().connect();
                }
            });
        }
        service.shutdown();
        try {
            service.awaitTermination(1, TimeUnit.HOURS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Connection {
    private static Connection instance = new Connection();
    private Semaphore semaphore = new Semaphore(10);
    private int connections = 0;

    private Connection(){
    }

    public static Connection getInstance() {
        return instance;
    }

    public void connect() {
        try {
            semaphore.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        try {
            doConnect();
        } finally {
            semaphore.release();
        }
    }

    public void doConnect() {

        synchronized (this) {
            connections++;
            System.out.println("connections = " + connections);
        }
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        synchronized (this) {
            connections--;
        }
    }
}