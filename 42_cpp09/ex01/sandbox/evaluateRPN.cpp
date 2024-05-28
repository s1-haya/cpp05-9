#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

bool isOperator(const std::string &token) {
  return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isNumber(const std::string &token) {
  if (token.length() != 1) return false;
  return std::isdigit(token[0]);
}

int applyOperator(int a, int b, const std::string &op) {
  if (op == "+") return a + b;
  if (op == "-") return a - b;
  if (op == "*") return a * b;
  if (op == "/") {
    if (b == 0) throw std::runtime_error("Error");
    return a / b;
  }
  throw std::runtime_error("Error");
}

int evaluateRPN(const std::string &input) {
  std::istringstream inputStream(input);
  std::stack<int> stack;
  std::string token;

  while (inputStream >> token) {
    if (isNumber(token)) {
      std::istringstream numberStream(token);
      int number;
      numberStream >> number;
      stack.push(number);
    } else if (isOperator(token)) {
      if (stack.size() < 2) throw std::runtime_error("Error");
      int b = stack.top();
      stack.pop();
      int a = stack.top();
      stack.pop();
      int result = applyOperator(a, b, token);
      stack.push(result);
    } else {
      throw std::runtime_error("Error");
    }
  }

  if (stack.size() != 1) throw std::runtime_error("Error");
  return stack.top();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " \"N N Op ...\"" << std::endl;
    std::cout << "N: 0 ~ 9" << std::endl;
    std::cout << "Op: + - * /" << std::endl;
    std::cout << "To learn more about RPN, ask hayato." << std::endl;
    return 1;
  }

  const std::string input(argv[1]);

  try {
    std::cout << evaluateRPN(input) << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  return 0;
}
