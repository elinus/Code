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

import java.util.Iterator;
import java.util.Random;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

public class ReaderThread extends Thread {
    private final Random random = new Random();
    private ConcurrentMap<Integer, String> map;
    private String name;

    public ReaderThread(ConcurrentMap<Integer, String> map, String name) {
        this.map = map;
        this.name = name;
    }

    @Override
    public void run() {
        while (true) {
            ConcurrentHashMap.KeySetView<Integer, String> keySetView =
                    (ConcurrentHashMap.KeySetView<Integer, String>) map.keySet();
            Iterator<Integer> iterator = keySetView.iterator();
            long time = System.currentTimeMillis();
            String output = time + ": " + name + ": ";
            while (iterator.hasNext()) {
                Integer key = iterator.next();
                String value = (String) map.get(key);
                output += key + "=>" + value + "; ";
            }
            System.out.println(output);
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
