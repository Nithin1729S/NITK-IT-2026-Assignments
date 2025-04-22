import java.util.Scanner;

public class Quadrilaterals {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt user for side length of a square
        System.out.print("Enter the side length of the square: ");
        double sideLength = scanner.nextDouble();

        // Create multiple objects for square and calculate area and perimeter
        Square square1 = new Square(sideLength);
        Square square2 = new Square(7); // Example with different side length

        System.out.println("Square 1:");
        System.out.println("Area: " + square1.calculateArea());
        System.out.println("Perimeter: " + square1.calculatePerimeter());

        System.out.println("\nSquare 2:");
        System.out.println("Area: " + square2.calculateArea());
        System.out.println("Perimeter: " + square2.calculatePerimeter());

        // Create a rectangle and calculate area and perimeter
        Rectangle rectangle = new Rectangle(4, 6);
        System.out.println("\nRectangle:");
        System.out.println("Area: " + rectangle.calculateArea());
        System.out.println("Perimeter: " + rectangle.calculatePerimeter());

        // Test Quadrilaterals
        TestQuadrilaterals test = new TestQuadrilaterals(square1, rectangle);
        test.printDetails();
    }
}

class Square {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    public double calculateArea() {
        return side * side;
    }

    public double calculatePerimeter() {
        return 4 * side;
    }
}

class Rectangle {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double calculateArea() {
        return length * width;
    }

    public double calculatePerimeter() {
        return 2 * (length + width);
    }
}

class TestQuadrilaterals {
    private Square square;
    private Rectangle rectangle;

    public TestQuadrilaterals(Square square, Rectangle rectangle) {
        this.square = square;
        this.rectangle = rectangle;
    }

    public void printDetails() {
        System.out.println("\nTesting Quadrilaterals:");
        System.out.println("Square details:");
        System.out.println("Area: " + square.calculateArea());
        System.out.println("Perimeter: " + square.calculatePerimeter());

        System.out.println("\nRectangle details:");
        System.out.println("Area: " + rectangle.calculateArea());
        System.out.println("Perimeter: " + rectangle.calculatePerimeter());
    }
}
