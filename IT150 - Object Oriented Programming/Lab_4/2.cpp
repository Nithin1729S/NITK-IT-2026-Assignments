#include <iostream>

class Shape
{
public:
    virtual double area() const = 0;
    virtual void display() const
    {
        std::cout << "Shape" << std::endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override
    {
        return 3.14 * radius * radius;
    }

    void display() const override
    {
        std::cout << "Circle" << std::endl;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override
    {
        return length * width;
    }

    void display() const override
    {
        std::cout << "Rectangle" << std::endl;
    }
};

int main()
{

    double circleRadius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> circleRadius;

    double rectangleLength, rectangleWidth;
    std::cout << "Enter the length and width of the rectangle (separated by space): ";
    std::cin >> rectangleLength >> rectangleWidth;

    Circle circle(circleRadius);
    Rectangle rectangle(rectangleLength, rectangleWidth);

    Shape *shape1 = &circle;
    Shape *shape2 = &rectangle;

    shape1->display();
    std::cout << "Area: " << shape1->area() << std::endl;

    shape2->display();
    std::cout << "Area: " << shape2->area() << std::endl;

    return 0;
}
