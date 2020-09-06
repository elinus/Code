package DesignPatterns.Behavioral.State;

public class TvStartState implements State {
    @Override
    public void doAction() {
        System.out.println("TV is turned ON");
    }
}
