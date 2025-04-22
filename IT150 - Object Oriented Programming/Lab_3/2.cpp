#include<iostream>
#include<cmath>


double calculateArea(double side); 
double calculateArea(double length, double width); 
double calculateAreaCircle(double radius); 
int calculateArea(int side); 

int main() {
    double length, width, radius;
    int side;

    
    std::cout << "Enter the side length of the square: ";
    std::cin >> side;
    std::cout << "Area of the square: " << calculateArea(side) << std::endl;

    
    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length;
    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width;
    std::cout << "Area of the rectangle: " << calculateArea(length, width) << std::endl;

    
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    std::cout << "Area of the circle: " << calculateArea(radius) << std::endl;

    return 0;
}


double calculateArea(double side) {
    return side * side;
}


double calculateArea(double length, double width) {
    return length * width;
}


double calculateAreaCircle(double radius) {
    return M_PI * radius * radius;
}


int calculateArea(int side) {
    return side * side;
}
