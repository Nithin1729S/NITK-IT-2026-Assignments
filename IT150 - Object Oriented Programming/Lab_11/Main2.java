// Compile-time polymorphism (Method Overloading)
class MathOperations {
    // Method overloading
    int add(int a, int b) {
        return a + b;
    }

    // Method overloading
    double add(double a, double b) {
        return a + b;
    }
}

// Runtime polymorphism (Method Overriding)
class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal {
    @Override
    void sound() {
        System.out.println("Cat meows");
    }
}

public class Main2 {
    public static void main(String[] args) {
        // Compile-time polymorphism (Method Overloading)
        MathOperations math = new MathOperations();
        int sum1 = math.add(5, 7);
        double sum2 = math.add(3.5, 2.5);
        System.out.println("Sum of integers: " + sum1);
        System.out.println("Sum of doubles: " + sum2);

        // Runtime polymorphism (Method Overriding)
        Animal animal1 = new Dog(); // Upcasting
        Animal animal2 = new Cat(); // Upcasting

        animal1.sound(); // Calls Dog's sound() method at runtime
        animal2.sound(); // Calls Cat's sound() method at runtime
    }
}
