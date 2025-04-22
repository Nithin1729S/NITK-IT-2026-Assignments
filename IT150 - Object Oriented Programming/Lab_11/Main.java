// Abstract class
abstract class Animal {
    String name;

    // Abstract method
    abstract void makeSound();

    // Constructor
    Animal(String name) {
        this.name = name;
    }
}

// Subclass inheriting from Animal
class Dog extends Animal {
    // Constructor calling super constructor
    Dog(String name) {
        super(name);
    }

    // Method overriding
    @Override
    void makeSound() {
        System.out.println(name + " says Woof!");
    }

    // Method overloading
    void makeSound(int times) {
        for (int i = 0; i < times; i++) {
            System.out.println(name + " says Woof!");
        }
    }
}

// Another subclass inheriting from Animal
class Cat extends Animal {
    // Constructor calling super constructor
    Cat(String name) {
        super(name);
    }

    // Method overriding
    @Override
    void makeSound() {
        System.out.println(name + " says Meow!");
    }
}

public class Main {
    public static void main(String[] args) {
        // Dynamic binding
        Animal animal1 = new Dog("Buddy");
        Animal animal2 = new Cat("Whiskers");

        // Method overriding and dynamic binding
        animal1.makeSound(); // Calls Dog's makeSound()
        animal2.makeSound(); // Calls Cat's makeSound()

        // Method overloading
        Dog dog = new Dog("Rex");
        dog.makeSound(3); // Calls Dog's makeSound(int times)

        // Final keyword
        final int x = 10; // Final variable
        // x = 20; // This will cause a compilation error since x is final
    }
}
