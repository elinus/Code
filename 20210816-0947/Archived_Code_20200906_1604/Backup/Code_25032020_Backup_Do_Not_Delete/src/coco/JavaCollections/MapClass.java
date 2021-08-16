package coco.JavaCollections;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class MapClass {

    public static void main(String[] args) {
        Map map = new HashMap();

        map.put("A", "1");
        map.put("B", "2");
        map.put("C", "3");

        Iterator iterator1 = map.keySet().iterator();
        while (iterator1.hasNext()) {
            Object key = iterator1.next();
            Object value = map.get(key);
        }

        Iterator iterator2 = map.values().iterator();
        while (iterator2.hasNext()) {
            Object value = iterator2.next();
        }

        Set entries = map.entrySet();
        Iterator iterator3 = entries.iterator();
        while (iterator3.hasNext()) {
            Map.Entry entry = (Map.Entry) iterator3.next();
            Object key = entry.getKey();
            Object value = entry.getValue();
        }
    }
}
