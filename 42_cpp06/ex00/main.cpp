#include "ScalarConverter.hpp"
void runTest(void);

int main(int argc, char **argv) {
  if (argc == 2)
    ScalarConverter::convert(argv[1]);
  else
    runTest();
  return (0);
}
