#include <iostream>
#include <sstream>
#include <limits>

void checkOverflowInt(const std::string &literal) {
  int nb;
  std::stringstream ss(literal);

  ss >> nb;
  if (ss.fail())
    std::cout << "Int: impossible" << std::endl;
  else
    std::cout << "Int: " << nb << std::endl;
}

int main() {
	checkOverflowInt("2147483647");
	checkOverflowInt("2147483648");
	checkOverflowInt("1.79769e+308.0");
	checkOverflowInt("2.22507e-308");

    double largeValue = 1.7976931348623157e+308; // 大きな値
    double smallValue = 2.2250738585072014e-308; // 小さな値

    // std::cout << std::numeric_limits<int>::min() << std::endl;
    // std::cout << std::numeric_limits<float>::min() << std::endl;
    // std::cout << std::numeric_limits<int>::max() << std::endl;
    // std::cout << std::numeric_limits<float>::max() << std::endl;
    std::cout << std::numeric_limits<double>::min() << std::endl;
    std::cout << static_cast<float>(std::numeric_limits<float>::min()) - 1 << std::endl;
    std::cout << static_cast<float>(std::numeric_limits<double>::min()) << std::endl;
    std::cout << std::numeric_limits<double>::max() << std::endl;
    std::cout << static_cast<float>(std::numeric_limits<double>::max()) << std::endl;

    if (std::numeric_limits<float>::max() < std::numeric_limits<double>::max() - 1)
        std::cout << "Float value overflow occurred!" << std::endl;
    if (static_cast<double>(std::numeric_limits<float>::min()) > std::numeric_limits<double>::min())
        std::cout << "Float value overflow occurred!" << std::endl;


    if (largeValue > static_cast<double>(std::numeric_limits<int>::max())) {
        std::cout << "Large value overflow occurred!" << std::endl;
    } else {
        std::cout << "No large value overflow occurred." << std::endl;
    }

    if (smallValue < static_cast<double>(std::numeric_limits<int>::min())) {
        std::cout << "Small value overflow occurred!" << std::endl;
    } else {
        std::cout << "No small value overflow occurred." << std::endl;
    }

    if (std::numeric_limits<double>::min() < static_cast<double>(std::numeric_limits<int>::min())) {
        std::cout << "Small value overflow occurred!" << std::endl;
    } else {
        std::cout << "No small value overflow occurred." << std::endl;
    }
	return (0);
}
