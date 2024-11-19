#include "ExpressionEvaluator.h"
#include <stack>
#include <sstream>
#include <iostream>
#include <cctype>

int evaluatePostfix(const std::string& expression) {
    std::stack<int> s;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            // Convert char digit to int and push onto the stack
            s.push(token[0] - '0');
        } else if (token.size() == 1 && std::string("+-*/").find(token) != std::string::npos) {
            if (s.size() < 2) throw std::invalid_argument("Invalid expression: Not enough operands.");
            
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b == 0) throw std::invalid_argument("Division by zero.");
                    result = a / b; 
                    break;
                default:
                    throw std::invalid_argument("Unsupported operator: " + token);
            }
            s.push(result);
        } else {
            throw std::invalid_argument("Invalid token: " + token);
        }
    }

    if (s.size() != 1) throw std::invalid_argument("Invalid expression: Improper number of operators.");
    return s.top();
}
