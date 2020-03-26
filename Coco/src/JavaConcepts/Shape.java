package JavaConcepts;

public class Shape {
    public void draw() {
        System.out.println("Drawing shape!");
    }

    public static void main(String[] args) {

        Shape shape = new Rectangle();
        shape.draw();

        shape = new Circle();
        shape.draw();
    }
}

class Rectangle extends Shape {
    @Override
    public void draw() {
        System.out.println("Rectangle = []");
    }
}

class Circle extends Shape {
    @Override
    public void draw() {
        System.out.println("Circle = ()");
    }
}


