package JavaConcepts;

import java.util.*;

public class CollectionsListTest {

    public static void main(String[] args) {
        List list = new ArrayList();
        // public class ArrayList<E> extends AbstractList<E> implements List<E>, RandomAccess, Cloneable, Serializable
        // public abstract class AbstractList<E> extends AbstractCollection<E> implements List<E>
        // public abstract class AbstractCollection<E> implements Collection<E>
        // public interface Collection<E> extends Iterable<E>
        // public interface Iterable<T>

        list = new LinkedList();
        // public class LinkedList<E> extends AbstractSequentialList<E> implements List<E>, Deque<E>, Cloneable, Serializable
        // public abstract class AbstractSequentialList<E> extends AbstractList<E>
        // public abstract class AbstractList<E> extends AbstractCollection<E> implements List<E>
        // public abstract class AbstractCollection<E> implements Collection<E>
        // public interface Collection<E> extends Iterable<E>
        // public interface Iterable<T>

        list = new Stack();
        // public class Stack<E> extends Vector<E>
        // public class Vector<E> extends AbstractList<E> implements List<E>, RandomAccess, Cloneable, Serializable

        list = new Vector();
        // public class Vector<E> extends AbstractList<E> implements List<E>, RandomAccess, Cloneable, Serializable

    }
}
