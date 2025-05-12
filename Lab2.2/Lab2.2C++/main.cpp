#include <iostream>
#include "Shapes.h"

using namespace std;

void printShapeInfo(const Shape& shape) {
    cout << "Shape: " << shape.getName() << endl;
    cout << "Area: " << shape.calculateArea() << endl;
    cout << "Perimeter: " << shape.calculatePerimeter() << endl;
    cout << "------------------------" << endl;
}

int main() {
    Square square(0, 0, 2, 0, 2, 2, 0, 2);

    Circle circle(3);

    Shape* shapes[] = { &square, &circle };

    for (Shape* shape : shapes) {
        printShapeInfo(*shape);
    }

    return 0;
}