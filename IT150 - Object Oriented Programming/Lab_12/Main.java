class MobileOS {
    public void display() {
        System.out.println("Displaying in Mobile OS");
    }
}

class AndroidOS extends MobileOS {
    @Override
    public void display() {
        System.out.println("Displaying in Android OS");
    }
}

class IOSOS extends MobileOS {
    @Override
    public void display() {
        System.out.println("Displaying in iOS OS");
    }
}

public class Main {
    public static void main(String[] args) {
        // Upcasting AndroidOS object to MobileOS reference
        MobileOS android = new AndroidOS();
        // Upcasting IOSOS object to MobileOS reference
        MobileOS ios = new IOSOS();

        // Demonstrating runtime polymorphism by invoking display method
        // through MobileOS reference, which will call appropriate display method
        // based on the actual object type
        android.display(); // Displaying in Android OS
        ios.display();     // Displaying in iOS OS
    }
}
