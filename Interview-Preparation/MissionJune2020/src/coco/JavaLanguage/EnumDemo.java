package coco.JavaLanguage;

enum Level {
    HIGH,
    NORMAL,
    LOW
}

class EnumDemo {

    public static void main(String[] args) {

        for (Level level : Level.values()) {
            System.out.println(level);
        }

        String high = Level.HIGH.toString();
        System.out.println(Level.NORMAL);

        Level level = Level.valueOf("LOW");
    }
}
