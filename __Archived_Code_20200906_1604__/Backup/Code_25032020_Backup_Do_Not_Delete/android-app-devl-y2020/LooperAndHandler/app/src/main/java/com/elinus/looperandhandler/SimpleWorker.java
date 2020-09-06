package com.elinus.looperandhandler;

import android.util.Log;

import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.atomic.AtomicBoolean;

public class SimpleWorker extends Thread {

    private static final String TAG = SimpleWorker.class.getSimpleName();
    private AtomicBoolean alive = new AtomicBoolean(true);
    private ConcurrentLinkedQueue<Runnable> taskQueue = new ConcurrentLinkedQueue<>();

    SimpleWorker() {
        super(TAG);
        start();
    }

    @Override
    public void run() {
        while (alive.get()) {
            Runnable task = taskQueue.poll();
            if (task != null) {
                task.run();
            }
        }
        Log.i(TAG, "SimpleWorker Terminated!");
    }

    public SimpleWorker execute(Runnable task) {
        taskQueue.add(task);
        return this;
    }

    public void quit() {
        alive.set(false);
    }
}
