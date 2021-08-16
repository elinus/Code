package coco;

import java.util.ArrayList;
import java.util.List;

public class Main extends Thread {

    private List<String> us;

    public Main(List<String> us) {
        System.out.println("tid(main) :: " + Thread.currentThread().getName());
        this.us = us;
    }

    @Override
    public void run() {
        for (String str: us) {
            System.out.println("tid = " + Thread.currentThread().getName());
            System.out.println(str);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("tid(main) :: " + Thread.currentThread().getName());
        System.out.println("Coco # 2020/03/27 05:35 AM");
        ArrayList<String> us = new ArrayList<>();
        us.add("Sunil");
        us.add("Akanksha");
        us.add("Coco");
        us.add("Zaki");
        Main mainObj = new Main(us);
        mainObj.run();
    }
}
