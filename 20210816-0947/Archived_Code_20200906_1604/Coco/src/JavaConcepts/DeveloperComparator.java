package JavaConcepts;

import java.util.Comparator;

public class DeveloperComparator implements Comparator<Developer> {
    @Override
    public int compare(Developer d1, Developer d2) {
        return d1.level - d2.level;
    }
}
