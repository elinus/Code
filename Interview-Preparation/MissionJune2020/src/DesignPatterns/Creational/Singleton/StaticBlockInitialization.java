package DesignPatterns.Creational.Singleton;

public class StaticBlockInitialization {
    private static StaticBlockInitialization instance;
    private StaticBlockInitialization(){}
    public static StaticBlockInitialization getInstance() {
        return instance;
    }
    static {
        try {
            instance = new StaticBlockInitialization();
        } catch (Exception e) {
            throw new RuntimeException("Exception occurred while creating singleton instance.");
        }
    }
}
