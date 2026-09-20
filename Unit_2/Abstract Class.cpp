#include <iostream>                  // Includes the input-output stream library.

// Defines Shape as an abstract base class.
class Shape {

public:                              // Makes the following members publicly accessible.

    // Declares a pure virtual function named area().
    virtual double area() const = 0;

    // Declares a virtual destructor.
    virtual ~Shape() = default;
};

// Defines Rectangle as a derived class of Shape.
class Rectangle : public Shape {

private:                             // Makes the following data members private.

    // Stores the length of the rectangle.
    double length;

    // Stores the width of the rectangle.
    double width;

public:                              // Makes the following members publicly accessible.

    // Parameterized constructor of Rectangle.
    Rectangle(double givenLength, double givenWidth)

        // Initializes length and width.
        : length(givenLength), width(givenWidth) {}

    // Overrides the pure virtual area() function.
    double area() const override {

        // Calculates and returns the area of the rectangle.
        return length * width;
    }
};

// Defines Circle as a derived class of Shape.
class Circle : public Shape {

private:                             // Makes radius private.

    // Stores the radius of the circle.
    double radius;

public:                              // Makes the following members publicly accessible.

    // Parameterized constructor of Circle.
    explicit Circle(double givenRadius)

        // Initializes radius.
        : radius(givenRadius) {}

    // Overrides the pure virtual area() function.
    double area() const override {

        // Calculates and returns the area of the circle.
        return 3.141592653589793 * radius * radius;
    }
};

// Main function where program execution starts.
int main() {

    // Creates a Rectangle object with length 5 and width 3.
    Rectangle rectangle(5.0, 3.0);

    // Creates a Circle object with radius 2.
    Circle circle(2.0);

    // Displays the area of the rectangle.
    std::cout << "Rectangle Area: " << rectangle.area() << '\n';

    // Displays the area of the circle.
    std::cout << "Circle Area: " << circle.area() << '\n';

    // Returns 0 for successful execution.
    return 0;
}
