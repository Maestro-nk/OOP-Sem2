#include "Expression.h"

Expression::Expression(double a, double b, double c) : a(a), b(b), c(c) {}

double Expression::getA() const { return a; }
double Expression::getB() const { return b; }
double Expression::getC() const { return c; }

void Expression::setA(double value) { a = value; }
void Expression::setB(double value) { b = value; }
void Expression::setC(double value) { c = value; }

double Expression::calculateLogarithm(double value) const {
    if (value <= 0) {
        throw NegativeLogarithmException();
    }
    return log(value);
}

double Expression::calculate() const {
    try {
        double logResult = calculateLogarithm(a);
        return (logResult + b) / c;
    }
    catch (const NegativeLogarithmException& e) {
        throw; // Перебрасываем исключение дальше
    }
}