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
import java.util.concurrent.ConcurrentNavigableMap;
import java.util.concurrent.ConcurrentSkipListMap;

public class ConcurrentNavigableMapExample {
    public static void main(String[] args) {
        ConcurrentNavigableMap map = new ConcurrentSkipListMap();
        map.put("1", "one");
        map.put("2", "two");
        map.put("3", "three");
        map.put("4", "four");
        map.put("5", "five");

        ConcurrentNavigableMap headMap = map.headMap("2");
        Iterator iterator = headMap.keySet().iterator();
        while (iterator.hasNext()) {
            System.out.println("headMap = " + iterator.next());
        }

        ConcurrentNavigableMap tailMap = map.tailMap("2");
        iterator = tailMap.keySet().iterator();
        while (iterator.hasNext()) {
            System.out.println("tailMap = " + iterator.next());
        }

        ConcurrentNavigableMap subMap = map.subMap("2", "4");
        iterator = subMap.keySet().iterator();
        while (iterator.hasNext()) {
            System.out.println("subMap = " + iterator.next());
        }
    }
}
