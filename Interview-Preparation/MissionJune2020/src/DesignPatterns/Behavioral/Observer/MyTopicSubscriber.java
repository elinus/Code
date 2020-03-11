package DesignPatterns.Behavioral.Observer;

public class MyTopicSubscriber implements Observer {

    private String name;
    private Subject topic;

    public MyTopicSubscriber(String name) {
        this.name = name;
    }

    @Override
    public void update() {
        String msg = (String) topic.getUpdate(this);
        if (msg == null) {
            System.out.println("No new message :: " + name);
        } else {
            System.out.println(name + " :: Consuming :: " + msg);
        }
    }

    @Override
    public void setSubject(Subject subject) {
        topic = subject;
    }
}
