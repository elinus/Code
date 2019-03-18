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

import java.io.IOException;
import java.util.Random;
import java.util.concurrent.*;

public class CallableAndFutureApp {
    public static void main(String[] args) {
        ExecutorService service = Executors.newCachedThreadPool();
//        service.submit(new Runnable() {
//            @Override
//            public void run() {
//                Random random = new Random();
//                int duration = random.nextInt(4000);
//                System.out.println("Starting..");
//
//                try {
//                    Thread.sleep(duration);
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//                System.out.println("Finished..!");
//            }
//        });

        Future<Integer> future = service.submit(new Callable<Integer>() {
            @Override
            public Integer call() throws Exception {
                Random random = new Random();
                int duration = random.nextInt(4000);

                if (duration > 2000) {
                    throw new IOException("Sleeping for too long..");
                }

                System.out.println("Starting..");

                try {
                    Thread.sleep(duration);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("Finished..!");
                return duration;
            }
        });

        service.shutdown();

        try {
            System.out.println("future = " + future.get());
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        }
    }
}
