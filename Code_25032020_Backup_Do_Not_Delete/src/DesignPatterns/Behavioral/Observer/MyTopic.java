package DesignPatterns.Behavioral.Observer;

import java.util.ArrayList;
import java.util.List;

public class MyTopic implements Subject {

    private List<Observer> observers;
    private String message;
    private boolean changed;
    private final Object mutex = new Object();

    public MyTopic() {
        observers = new ArrayList<>();
    }

    @Override
    public void register(Observer observer) {
        if (observer == null) throw new NullPointerException("Observer is null");
        synchronized (mutex) {
            if (!observers.contains(observer))
                observers.add(observer);
        }
    }

    @Override
    public void unregister(Observer observer) {
        synchronized (mutex) {
            observers.remove(observer);
        }
    }

    @Override
    public void notifyObservers() {
        List<Observer> observerList = null;
        synchronized (mutex) {
            if (!changed)
                return;
            observerList = new ArrayList<>(this.observers);
            changed = false;
        }
        for (Observer o : observerList) {
            o.update();
        }
    }

    @Override
    public Object getUpdate(Observer observer) {
        return message;
    }

    public void postMessage(String msg) {
        System.out.println("Message Posted to Topic: " + msg);
        message = msg;
        changed = true;
        notifyObservers();
    }
}
