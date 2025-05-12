#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdexcept>
#include <cmath>

class NegativeLogarithmException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Attempt to calculate logarithm of non-positive number";
    }
};

class Expression {
private:
    double a;
    double b;
    double c;

public:
    Expression(double a, double b, double c);

    double getA() const;
    double getB() const;
    double getC() const;

    void setA(double value);
    void setB(double value);
    void setC(double value);

    double calculate() const;
    double calculateLogarithm(double value) const;
};

#endif // EXPRESSION_H#pragma once
