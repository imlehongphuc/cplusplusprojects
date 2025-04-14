#include "circle.h"
#include <iostream>
#include <cmath>
using namespace std;

Circle::Circle() : PI(3.14159), radius(0.0) {} // Default constructor
Circle::Circle(double r) : PI(3.14159) // Constructor with parameters
{
    if (r >= 0)
    {
        radius = r;
    }
    else 
    {
        // Handle invalid radius input
        cerr << "Invalid radius input!" << endl;
        radius = 0.0; // Set radius to default value
    }
}
// Function getRadius
double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    if (r >= 0)
    {
        radius = r;
    }
    else 
    {
        // Handle invalid radius input
        cerr << "Invalid radius input!" << endl;
    }
}

// Function getDiameter
double Circle::getDiameter() const {
    return 2 * radius;
}

// Function getCircumference
double Circle::getCircumference() const {
    return 2 * PI * radius;
}

// Function getArea
double Circle::getArea() const {
    return PI * pow(radius, 2);
}
