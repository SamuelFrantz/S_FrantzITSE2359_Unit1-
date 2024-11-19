#include <iostream>
#include <string>
#include "ExpressionEvaluator.h"

int main() {
    std::string expression;
    std::cout << "Enter a postfix expression: ";
    std::getline(std::cin, expression);

    try {
        int result = evaluatePostfix(expression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
