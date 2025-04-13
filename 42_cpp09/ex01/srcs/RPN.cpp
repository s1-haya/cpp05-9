#include "RPN.hpp"

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::is_valid_token(const std::string& token) {
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;
    if (token.length() == 1 && isdigit(token[0]))
        return true;
    return false;
}

bool RPN::validate_input_format(const std::string& input) {
    if (input.empty() || input[0] == ' ' || input[input.length() - 1] == ' ')
        return false;

    for (std::string::size_type i = 0; i < input.length(); ++i) {
        if (input[i] == ' ' && i + 1 < input.length() && input[i + 1] == ' ')
            return false;
    }

    std::istringstream ss(input);
    std::string token;
    while (ss >> token) {
        if (!is_valid_token(token))
            return false;
    }

    return true;
}

int RPN::calculate(const std::string& input) {
    if (!validate_input_format(input)) {
        throw std::invalid_argument("Invalid input format");
    }

    std::istringstream ss(input);
    std::stack<int> s;
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            s.push(token[0] - '0');
        } else {
            if (s.size() < 2) {
                throw std::invalid_argument("insufficient values for operation");
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0) {
                    throw std::invalid_argument("division by zero");
                }
                result = a / b;
            }
            s.push(result);
        }
    }
	int result = s.top();
	s.pop();
	if (!s.empty()) {
        throw std::invalid_argument("too many values remaining");
	}
	return result;
}
