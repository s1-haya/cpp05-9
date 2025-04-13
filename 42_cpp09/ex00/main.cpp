#include "BitcoinExchange.hpp"
#include <iostream>

void runTest(void);

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return ERROR;
	}
	#ifdef DEBUG
		runTest();
	#endif
	BitcoinExchange bitcoinExchange;
	// BitcoinExchange bitcoinExchange("test/csv_error/invalid_header.csv");
	return bitcoinExchange.process(argv[1]);
}
