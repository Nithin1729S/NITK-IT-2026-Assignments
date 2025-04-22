class MultipleConstructors {
    private int a;
    private int b;

    // Constructor with multiple parameters
    public MultipleConstructors(int a, int b) {
        this.a = a;
        this.b = b;
    }

    // Constructor with one parameter and others default
    public MultipleConstructors(int a) {
        this(a, 0); // Using 'this' to call another constructor
    }

    // Constructor in terms of another object
    public MultipleConstructors(MultipleConstructors obj) {
        this.a = obj.a;
        this.b = obj.b;
    }

    // Default constructor
    public MultipleConstructors() {
        this(0, 0); // Using 'this' to call another constructor
    }

    public void display() {
        System.out.println("Value of a: " + this.a);
        System.out.println("Value of b: " + this.b);
    }
}

public class Mul {
    public static void main(String[] args) {
        MultipleConstructors obj1 = new MultipleConstructors(10, 20);
        obj1.display();

        MultipleConstructors obj2 = new MultipleConstructors(30);
        obj2.display();

        MultipleConstructors obj3 = new MultipleConstructors(obj1);
        obj3.display();

        MultipleConstructors obj4 = new MultipleConstructors();
        obj4.display();
    }
}
