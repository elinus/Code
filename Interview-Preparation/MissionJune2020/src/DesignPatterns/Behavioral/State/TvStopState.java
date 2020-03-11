package DesignPatterns.Behavioral.State;

public class TvStopState implements State {
    @Override
    public void doAction() {
        System.out.println("TV is turned OFF");
    }
}
