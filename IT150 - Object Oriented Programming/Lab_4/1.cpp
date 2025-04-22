#include <iostream>

template <typename T>
class Shape
{
public:
    virtual T area() const = 0;
};

template <typename T>
class Circle : public Shape<T>
{
private:
    T radius;

public:
    Circle(T r) : radius(r) {}

    T area() const override
    {
        return 3.14 * radius * radius;
    }
};

template <typename T>
class Rectangle : public Shape<T>
{
private:
    T length;
    T width;

public:
    Rectangle(T l, T w) : length(l), width(w) {}

    T area() const override
    {
        return length * width;
    }
};

int main()
{

    double circleRadius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> circleRadius;

    int rectangleLength, rectangleWidth;
    std::cout << "Enter the length and width of the rectangle (separated by space): ";
    std::cin >> rectangleLength >> rectangleWidth;

    Circle<double> circle(circleRadius);
    Rectangle<int> rectangle(rectangleLength, rectangleWidth);

    Shape<double> *shape1 = &circle;
    Shape<int> *shape2 = &rectangle;

    std::cout << "Circle Area: " << shape1->area() << std::endl;
    std::cout << "Rectangle Area: " << shape2->area() << std::endl;

    return 0;
}
