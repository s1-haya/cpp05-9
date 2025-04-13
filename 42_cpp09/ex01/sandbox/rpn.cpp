#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

bool is_valid_token(const std::string& token) {
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;
    if (token.length() == 1 && isdigit(token[0]))
        return true;
    return false;
}

bool validate_input_format(const std::string& input) {
    // 入力が空 or 先頭・末尾空白を含む場合はNG
    if (input.empty() || input[0] == ' ' || input[input.length() - 1] == ' ')
        return false;

    for (std::string::size_type i = 0; i < input.length(); ++i) {
        if (input[i] == ' ' && i + 1 < input.length() && input[i + 1] == ' ')
            return false; // 連続スペース
    }

    std::istringstream ss(input);
    std::string token;
    while (ss >> token) {
        if (!is_valid_token(token))
            return false;
    }

    return true;
}

int rpn(const std::string& input) {
    if (!validate_input_format(input)) {
        std::cerr << "Error: invalid input format" << std::endl;
        return 1;
    }

    std::istringstream ss(input);
    std::stack<int> s;
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            s.push(token[0] - '0');
        } else {
            if (s.size() < 2) {
                std::cerr << "Error: insufficient values for operation" << std::endl;
                return 1;
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0) {
                    std::cerr << "Error: division by zero" << std::endl;
                    return 1;
                }
                result = a / b;
            }
            s.push(result);
        }
    }

    if (s.size() != 1) {
        std::cerr << "Error: invalid RPN expression" << std::endl;
        return 1;
    }

    std::cout << s.top() << std::endl;
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    return rpn(argv[1]);
}
