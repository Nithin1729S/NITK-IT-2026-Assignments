// Parent class
class Person {
    String name;
    int age;

    // Constructor
    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Method to display information
    void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

// Child class inheriting from Person - Employee
class Employee extends Person {
    double salary;

    // Constructor
    Employee(String name, int age, double salary) {
        super(name, age);
        this.salary = salary;
    }

    // Method to display employee information
    void displayEmployeeInfo() {
        System.out.println("-- Employee Information --");
        displayInfo(); // Calling method of the superclass
        System.out.println("Salary: $" + salary);
    }
}

// Child class inheriting from Person - Student
class Student extends Person {
    String major;

    // Constructor
    Student(String name, int age, String major) {
        super(name, age);
        this.major = major;
    }

    // Method to display student information
    void displayStudentInfo() {
        System.out.println("-- Student Information --");
        displayInfo(); // Calling method of the superclass
        System.out.println("Major: " + major);
    }
}

public class Main3 {
    public static void main(String[] args) {
        // Creating an Employee object
        Employee emp = new Employee("John Doe", 30, 50000);
        emp.displayEmployeeInfo(); // Displaying employee information

        System.out.println(); // Adding a newline for clarity

        // Creating a Student object
        Student student = new Student("Alice Smith", 20, "Computer Science");
        student.displayStudentInfo(); // Displaying student information
    }
}
