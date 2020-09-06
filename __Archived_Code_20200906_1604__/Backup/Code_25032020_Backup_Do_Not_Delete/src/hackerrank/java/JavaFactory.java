package hackerrank.java;

import java.util.*;
import java.security.*;

public class JavaFactory {
}

interface Food {
    public String getType();
}

class Pizza implements Food {
    public String getType() {
        return "Someone ordered a Fast Food!";
    }
}

class Cake implements Food {
    public String getType() {
        return "Someone ordered a Dessert!";
    }
}

class FoodFactory {

    public Food getFood(String order) {
        if (order.equalsIgnoreCase("cake")) {
            return new Cake();
        } else if (order.equalsIgnoreCase("pizza")) {
            return new Pizza();
        }
        return null;
    }
}
