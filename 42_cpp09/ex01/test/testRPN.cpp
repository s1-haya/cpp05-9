#include <iostream>
#include <sys/wait.h>
void testTitle(const std::string& title);

void testErrorCase(const std::string& input, const std::string& desc) {
    std::string command = "./RPN \"" + input + "\"";
    int ret = system(command.c_str());
    int exit_code = WEXITSTATUS(ret);
    std::cout << ret <<std::endl;
    std::cout << "exit code = " << exit_code << std::endl; 
    if (exit_code == 0) {
        std::cout << "[FAILED] " << desc << ": '" << input << "'" << std::endl;
    } else {
        std::cout << "[OK]     " << desc << std::endl;
    }
}

void testRPN() { 
    testTitle("Reverse Polish notation");
    testErrorCase("10 2 +", "Invalid number (number >= 10)");
    testErrorCase("1   2 +", "Multiple consecutive spaces");
    testErrorCase("1 2 + ", "Trailing space");
    testErrorCase(" 1 2 +", "Leading space");
    testErrorCase("1 2 3 +", "Too many operands");
    testErrorCase("1 +", "Too few operands");
    testErrorCase("1 0 /", "Division by zero");
    testErrorCase("a b +", "Invalid tokens (alphabet characters)");
    testErrorCase("(1 + 1)", "Invalid syntax (contains parentheses)");
    testErrorCase("1 2 + +", "Too many operators");
    testErrorCase("1 2 ?", "Invalid operator (not +, -, *, /)");
    testErrorCase("", "Empty input");
}
