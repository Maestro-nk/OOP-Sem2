#include <iostream>
#include <vector>
#include "Expression.h"

int main() {
    std::vector<Expression> expressions;

    try {
        expressions.emplace_back(1, 2, 3);
        expressions.emplace_back(4, 5, 6);
        expressions.emplace_back(-1, 2, 3); 

        for (size_t i = 0; i < expressions.size(); ++i) {
            try {
                double result = expressions[i].calculate();
                std::cout << "Expression " << i + 1 << ": "
                    << "(ln(" << expressions[i].getA() << ") + "
                    << expressions[i].getB() << ") / "
                    << expressions[i].getC() << " = "
                    << result << std::endl;
            }
            catch (const NegativeLogarithmException& e) {
                std::cerr << "Error in expression " << i + 1 << ": "
                    << e.what() << std::endl;
            }
        }

        double a, b, c;
        std::cout << "\nEnter values for a new expression (a b c): ";
        std::cin >> a >> b >> c;

        Expression userExpr(a, b, c);
        try {
            double result = userExpr.calculate();
            std::cout << "Result: " << result << std::endl;
        }
        catch (const NegativeLogarithmException& e) {
            std::cerr << "Calculation error: " << e.what() << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}