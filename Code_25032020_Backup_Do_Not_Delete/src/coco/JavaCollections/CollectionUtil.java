package coco.JavaCollections;

import java.util.*;

public class CollectionUtil {

    public static void foo(Collection collection) {
        Iterator iterator = collection.iterator();
        while (iterator.hasNext()) {
            Object object = iterator.next();
        }
    }

    public static void main(String[] args) {
        Set set = new HashSet();
        List list = new ArrayList();
        foo(set);
        foo(list);

        Collection collection = new HashSet();
        boolean inserted = collection.add("fizz");
        boolean removed = collection.remove("bar");

        collection.addAll(set);
        collection.addAll(list);

        collection.removeAll(set);
        collection.retainAll(list);

        collection.contains("foo");
        collection.containsAll(set);

        System.out.println("collection = " + collection.size());

        for (Object object: collection) {
            System.out.println(object);
        }

    }
}
