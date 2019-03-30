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

package InterviewPreparation2x19.Concurrency;

import java.util.concurrent.CyclicBarrier;

public class CyclicBarrierMain {

    public static void main(String[] args) {
        Runnable action1 = new Runnable() {
            @Override
            public void run() {
                System.out.println("Action 1 executed!");
            }
        };

        Runnable action2 = new Runnable() {
            @Override
            public void run() {
                System.out.println("Action 2 executed!");
            }
        };

        CyclicBarrier barrier1 = new CyclicBarrier(2, action1);
        CyclicBarrier barrier2 = new CyclicBarrier(2, action2);
        CyclicBarrierRunnable cbr1 =
                new CyclicBarrierRunnable(barrier1, barrier2);
        CyclicBarrierRunnable cbr2 =
                new CyclicBarrierRunnable(barrier1, barrier2);
        new Thread(cbr1).start();
        new Thread(cbr2).start();
    }
}
