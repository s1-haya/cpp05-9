#include <iostream>

#include "BitcoinExchange.hpp"

void runTest(void);

int main(int argc, char** argv) {
#ifdef DEBUG
	runTest();
	return SUCCESS;
#endif
  if (argc != 2) {
    std::cerr << "Usage: ./btc <input_file>" << std::endl;
    return ERROR;
  }
  BitcoinExchange bitcoin;
  // BitcoinExchange bitcoin("test/csv_error/invalid_header.csv");
  return bitcoin.process(argv[1]);
}
