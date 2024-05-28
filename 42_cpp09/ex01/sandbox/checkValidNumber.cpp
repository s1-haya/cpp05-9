#include <iostream>

void checkValidRPN(const std::string& input) {
	(void)input;
	// if (input)
		std::cout << "Success" << std::endl;
	// else
	// 	std::cerr << "Error:" << std::endl;
}

int main(void) {
	// You don’t need to manage the brackets or decimal numbers.
	// The numbers used in this operation and passed as arguments will always be less than 10. 
	// The calculation itself but also the result do not take into account this rule.
	// Your program must be able to handle operations with these tokens: "+ - / *"

	// sapce: by splited
	checkValidRPN("8 9 * 9 - 9 - 9 - 4 - 1 +");
	checkValidRPN("7 7 * 7 -");
	checkValidRPN("1 2 * 2 / 2 * 2 4 - +");
	checkValidRPN("(1 + 1)");
}
