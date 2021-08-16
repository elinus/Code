package coco.JavaLanguage;

@interface MyAnnotation {
    String   value();
    String   name();
    int      age();
    String[] newNames();
}

@MyAnnotation(value = "3412", name = "eli", age = 32, newNames = {"Sunil", "Mourya"})
public class AnnotationDemo {

    public static void main(String[] args) {

    }
}
