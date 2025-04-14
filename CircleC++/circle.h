#ifndef CIRCLES_H
#define CIRCLES_H

# start the main class
class Circle {
private:
// Declare constant variables and datatype variables
    const double PI;
    double radius;
public:
// Function Prototypes
    Circle(); // Default constructor
    Circle(double r); // Constructor with parameter
    double getRadius() const; // get radius
    void setRadius(double r); // set radius
    double getDiameter() const; // calculate diameter
    double getCircumference() const; // calculates circumference
    double getArea() const; // calculates area
};
#endif
