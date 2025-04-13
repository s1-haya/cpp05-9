#ifndef EX00_EASYFIND_HPP_
#define EX00_EASYFIND_HPP_

#include <string.h>

#include <map>

typedef std::map<int, float> DayBitcoin;
typedef std::map<int, DayBitcoin> MonthBitcoin;
typedef std::map<int, MonthBitcoin> YearBitcoin;

#define SUCCESS 0;
#define ERROR 1;

class BitcoinExchange {
 public:
  BitcoinExchange(const std::string &bitcoinFile = "test/data.csv");
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  int process(const std::string &inputFile);

 private:
  std::string bitcoinFile;
  void addBitcoin(YearBitcoin &map, const std::string &line);
  YearBitcoin getBitcoin();
  void processInputLine(const YearBitcoin &bitcoin, const std::string &line);
  int validateInputFile(const YearBitcoin &bitcoin,
                        const std::string &filename);
};

#endif
