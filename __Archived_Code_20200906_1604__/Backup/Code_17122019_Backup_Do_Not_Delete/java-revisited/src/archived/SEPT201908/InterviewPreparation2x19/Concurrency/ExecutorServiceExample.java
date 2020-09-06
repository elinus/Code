/**
 * Created on 31-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package archived.SEPT201908.InterviewPreparation2x19.Concurrency;

import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.concurrent.*;

public class ExecutorServiceExample {

    public static void main(String[] args) throws ExecutionException, InterruptedException {
        ExecutorService service = Executors.newFixedThreadPool(10);

        // Execute Runnable
        service.execute(new Runnable() {
            @Override
            public void run() {
                System.out.println("[" + Thread.currentThread().getName() + "] Asynchronous task!");
            }
        });

        Future future1 = service.submit(new Runnable() {
            @Override
            public void run() {
                System.out.println("[" + Thread.currentThread().getName() + "] Asynchronous task!");
            }
        });

        if (future1.get() == null) {
            System.out.println("Task completed successfully!");
        }

        // Submit Callable
        Future future2 = service.submit(new Callable<String>() {
            @Override
            public String call() throws Exception {
                System.out.println("[" + Thread.currentThread().getName() + "] Asynchronous Callable!");
                return "Callable Result";
            }
        });
        System.out.println("future2.get() = " + future2.get());

        Set<Callable<String>> callables = new HashSet<Callable<String>>();
        callables.add(new Callable<String>() {
            public String call() throws Exception {
                return "Task 1";
            }
        });
        callables.add(new Callable<String>() {
            public String call() throws Exception {
                return "Task 2";
            }
        });
        callables.add(new Callable<String>() {
            public String call() throws Exception {
                return "Task 3";
            }
        });
        String result = service.invokeAny(callables);
        System.out.println("result = " + result);

        List<Future<String>> futures = service.invokeAll(callables);
        for(Future<String> future : futures){
            System.out.println("future.get = " + future.get());
        }

        service.shutdown();
    }
}
