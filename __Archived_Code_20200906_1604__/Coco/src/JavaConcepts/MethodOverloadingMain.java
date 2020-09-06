package JavaConcepts;

public class MethodOverloadingMain {

    void foo(int i) {
        System.out.println("int :: " + i);
    }

    void foo(double d) {
        System.out.println("double :: " + d);
    }

    void foo(String s) {
        System.out.println("String :: " + s);
    }

    public static void main(String[] args) {
        MethodOverloadingMain obj = new MethodOverloadingMain();
        obj.foo(1);
        obj.foo(1.1);
        obj.foo("1.1");
    }
}
