#ifndef SHAPES_H
#define SHAPES_H

#include <string>

using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual string getName() const = 0;
};

class Square : public Shape {
private:
    double x1, y1, x2, y2, x3, y3, x4, y4;

public:
    Square(double x1, double y1, double x2, double y2,
        double x3, double y3, double x4, double y4);

    double calculateArea() const override;
    double calculatePerimeter() const override;
    string getName() const override;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius);

    double calculateArea() const override;
    double calculatePerimeter() const override;
    string getName() const override;
};

#endif // SHAPES_H#pragma once
