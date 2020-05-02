package DesignPatterns.Behavioral.State;

public class TvRemote {

    public static void main(String[] args) {
        TvContext tvContext = new TvContext();
        State tvStartState = new TvStartState();
        State tvStopState = new TvStopState();

        tvContext.setTvState(tvStartState);
        tvContext.doAction();

        tvContext.setTvState(tvStopState);
        tvContext.doAction();
    }
}
