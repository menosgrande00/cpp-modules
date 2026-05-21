#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    _stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(char op) {
    if (_stack.size() < 2) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    int num2 = _stack.top();
    _stack.pop();
    int num1 = _stack.top();
    _stack.pop();

    if (op == '/' && num2 == 0) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    if (op == '+') _stack.push(num1 + num2);
    else if (op == '-') _stack.push(num1 - num2);
    else if (op == '*') _stack.push(num1 * num2);
    else if (op == '/') _stack.push(num1 / num2);
}

void RPN::calculate(const std::string& expression) {
    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (c == ' ') {
            continue;
        }

        if (isdigit(c)) {
            _stack.push(c - '0');
        }
        else if (isOperator(c)) {
            performOperation(c);
        }
        else {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    std::cout << _stack.top() << std::endl;
}