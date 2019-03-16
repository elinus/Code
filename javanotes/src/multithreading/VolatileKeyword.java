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

package multithreading;

import java.util.Scanner;

class App3 extends Thread {

    private volatile boolean running = true;

    @Override
    public void run() {
        while (running) {
            System.out.println("Hello!");
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void shutdown() {
        running = false;
    }
}

public class VolatileKeyword {

    public static void main(String[] args) {
        App3 app3 = new App3();
        app3.start();

        System.out.println("Press <ENTER> to shutdown!");
        Scanner input = new Scanner(System.in);
        input.nextLine();

        app3.shutdown();
    }
}
