package coco.JavaCollections;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Person implements Iterable {
    private List<Person> persons = new ArrayList<>();

    @Override
    public Iterator<Person> iterator() {
        return this.persons.iterator();
    }

    public List<Person> getPersons() {
        return persons;
    }

    public static void main(String[] args) {
        Person pObj = new Person();
        for (Person p : pObj.getPersons()) {
        }
    }
}
