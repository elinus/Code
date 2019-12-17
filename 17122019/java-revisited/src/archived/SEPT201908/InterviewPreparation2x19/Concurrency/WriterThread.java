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

package archived.SEPT201908.InterviewPreparation2x19.Concurrency;

import java.util.Random;
import java.util.concurrent.ConcurrentMap;

public class WriterThread extends Thread {
    private final Random random = new Random();
    private ConcurrentMap<Integer, String> map;
    private String name;

    public WriterThread(ConcurrentMap<Integer, String> map, String name) {
        this.map = map;
        this.name = name;
    }

    @Override
    public void run() {
        while (true) {
            Integer key = random.nextInt(10);
            String value = name;
            if (map.putIfAbsent(key, value) == null) {
                long time= System.currentTimeMillis();
                String output = String.format("%d: %s has put [%d => %s]",
                        time, name, key, value);
                System.out.println(output);
            }

            Integer keyToRemove = random.nextInt(10);
            if (map.remove(keyToRemove, value)) {
                long time = System.currentTimeMillis();
                String output = String.format("%d: %s has put [%d => %s]",
                        time, name, keyToRemove, value);
            }

            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
