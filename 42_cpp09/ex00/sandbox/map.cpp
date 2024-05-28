#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

// std::map<std::string, float> getBitCoinData(std::ifstream file) {
//   std::string line;
//   while (std::getline(file, line)) {
//     std::cout << line << std::endl;
//   }
// }

typedef std::map<int, float> DayData;
typedef std::map<int, DayData> MonthData;
typedef std::map<int, MonthData> YearData;
void addData(YearData& map, const std::string& line);
void printData(const YearData& data);

YearData getDataDotCsv() {
  std::ifstream file("data.csv");
  if (!file.is_open()) {
    std::cerr << "Error: " << std::endl;
  }

  std::string line;
  if (!std::getline(file, line)) {
    std::cerr << "Error: Unable to read the header line" << std::endl;
  }
  YearData map;
  while (std::getline(file, line)) {
    addData(map, line);
  }
  return map;
}

// int main(void) {
//   YearData map = getDataDotCsv();
//   printData(map);
//   return 0;
// }
