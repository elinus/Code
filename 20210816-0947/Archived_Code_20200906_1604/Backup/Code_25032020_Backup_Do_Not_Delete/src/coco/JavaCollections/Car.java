package coco.JavaCollections;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Car {
    public String brand;
    public int price;

    public Car(String brand, int price) {
        this.brand = brand;
        this.price = price;
    }

    public static void main(String[] args) {

        List<Car> cars = new ArrayList<>();
        cars.add(new Car("KIA", 1800000));
        cars.add(new Car("Audi", 5000000));

        Comparator comparatorBrand = new Comparator<Car>() {
            @Override
            public int compare(Car c1, Car c2) {
                return c1.brand.compareTo(c2.brand);
            }
        };

        Comparator comparatorPrice = new Comparator<Car>() {
            @Override
            public int compare(Car c1, Car c2) {
                return c1.price - c2.price;
            }
        };

        Collections.sort(cars, comparatorPrice);
    }
}
