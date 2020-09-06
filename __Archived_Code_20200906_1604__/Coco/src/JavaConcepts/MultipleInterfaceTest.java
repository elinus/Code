package JavaConcepts;

interface IntA {
    void foo();
}

interface IntB extends IntA {
    void fizz();
}

public class MultipleInterfaceTest implements IntB {

    public static void main(String[] args) {

    }

    @Override
    public void foo() {

    }

    @Override
    public void fizz() {

    }
}

class ImplClone implements Cloneable {
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}