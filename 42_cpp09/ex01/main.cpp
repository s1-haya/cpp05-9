#include <iostream>

#include "RPN.hpp"

void runTest(void);

int main(const int argc, const char* argv[]) {
  #ifdef DEBUG
    runTest();
    return SUCCESS;
  #endif

  if (argc != 2) {
    std::cerr << "Usage: ./rpn \"<expression>\"" << std::endl;
    return ERROR;
  }

  RPN rpn;
  try {
    int result = rpn.calculate(argv[1]);
    std::cout << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return ERROR;
  }
  return SUCCESS;
}
