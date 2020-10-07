package coco.JavaCollections;

import java.util.Iterator;
import java.util.Properties;

public class PropertiesDemo {

    public static void main(String[] args) {
        Properties properties = System.getProperties();
        Iterator iterator = properties.keySet().iterator();
        while (iterator.hasNext()) {
            Object key = iterator.next();
            Object value = properties.get(key);
            System.out.println("key = " + key + ", value = " + value);
        }
    }
}
