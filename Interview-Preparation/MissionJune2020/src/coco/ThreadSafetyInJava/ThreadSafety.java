package coco.ThreadSafetyInJava;

public class ThreadSafety {

    public static void main(String[] args) {
        ProcessingThread pT = new ProcessingThread();
        Thread t1 = new Thread(pT, "t1");
        Thread t2 = new Thread(pT, "t2");
        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Processing count :: " + pT.getCount());
    }
}

class ProcessingThread implements Runnable {

    private final Object mutex = new Object();
    private int count = 0;

    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            doWork(i);
            synchronized (mutex) {
                count++;
            }
        }
    }

    public int getCount() {
        return count;
    }

    private void doWork(int fizz) {
        try {
            Thread.sleep(fizz * 100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}