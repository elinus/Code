/**
 * Created on 29-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package InterviewPreparation2x19.Concurrency;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.PriorityBlockingQueue;

public class PriorityBlockingQueueMain {
    public static void main(String[] args) {
        List employeeList = new ArrayList();
        employeeList.add(new Employee(0, "AAA"));
        employeeList.add(new Employee(1, "BBB"));
        employeeList.add(new Employee(2, "CCC"));
        employeeList.add(new Employee(3, "DDD"));
        employeeList.add(new Employee(4, "EEE"));
        employeeList.add(new Employee(5, "FFF"));
        employeeList.add(new Employee(6, "GGG"));
        employeeList.add(new Employee(7, "HHH"));
        employeeList.add(new Employee(8, "III"));
        employeeList.add(new Employee(9, "JJJ"));

        BlockingQueue<Employee> queue
                = new PriorityBlockingQueue<Employee>(5);
        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 10; i++) {
                    try {
                        queue.put((Employee) employeeList.get(i));
                        Thread.sleep(new Random().nextInt(1000));
                        System.out.println(Thread.currentThread().getName()
                                + ", put -> " + employeeList.get(i).toString());

                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        Thread t2 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 10; i++) {
                    try {
                        Thread.sleep(new Random().nextInt(1000));
                        Employee employee = queue.take();
                        System.out.println(Thread.currentThread().getName()
                                + ", take --->>> " + employee.toString());
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("exiting " + Thread.currentThread().getName() + " ..!");
    }
}
