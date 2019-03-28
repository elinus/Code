/**
 * Created on 28-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package InterviewPreparation2x19.Collections;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

public class MapExample {
    public static void main(String[] args) {
        System.out.println("---------- H A S H M A P----------");
        Map<String, String> hashMap = new HashMap<String, String>();
        hashMap.put("one", "first");
        hashMap.put("two", "second");
        hashMap.put("three", "third");
        Iterator iterator = hashMap.keySet().iterator();
        while (iterator.hasNext()) {
            Object key = iterator.next();
            Object value = hashMap.get(key);
            System.out.println("key = " + key + ", value = " + value);
        }

        System.out.println("---------- T R E E M A P ----------");
        Map<String, String> treeMap = new TreeMap<String, String>();
        treeMap.putAll(hashMap);
        iterator = treeMap.keySet().iterator();
        while (iterator.hasNext()) {
            Object key = iterator.next();
            Object value = treeMap.get(key);
            System.out.println("key = " + key + ", value = " + value);
        }
    }
}
