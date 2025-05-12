#define _USE_MATH_DEFINES

#include "Shapes.h"
#include <cmath>
#include <stdexcept>

using namespace std;

Square::Square(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {
}

double Square::calculateArea() const {
    double side = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return side * side;
}

double Square::calculatePerimeter() const {
    double side = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return 4 * side;
}

string Square::getName() const {
    return "Square";
}

Circle::Circle(double radius) : radius(radius) {
    if (radius <= 0) {
        throw invalid_argument("Radius must be positive");
    }
}

double Circle::calculateArea() const {
    return M_PI * radius * radius;
}

double Circle::calculatePerimeter() const {
    return 2 * M_PI * radius;
}

std::string Circle::getName() const {
    return "Circle";
}