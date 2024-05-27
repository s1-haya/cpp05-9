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

int main(void) {
  std::ifstream file("data.csv");
  if (!file.is_open()) {
    std::cerr << "Error: " << std::endl;
    return (1);
  }

  std::map<std::string, float> map;
  std::string line;
  if (!std::getline(file, line)) {
    std::cerr << "Error: Unable to read the header line" << std::endl;
    return (1);
  }
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string key, valueStr;
    if (std::getline(ss, key, ',') && std::getline(ss, valueStr, ',')) {
      std::istringstream valueStream(valueStr);
      float value;
      valueStream >> value;
      map[key] = value;
    }
  }

  std::map<std::string, float>::iterator it = map.begin();
  while (it != map.end()) {
    std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
    ++it;
  }

//   std::cout << "map: 2022-02-20 " << map["2022-02-20"] << std::endl;
//   std::cout << "map: 2022-02-20 " << map["2022-02-19"] << std::endl;
//   std::cout << "map: 2022-02-20 " << map["2022-02-20" - 1] << std::endl;
//   std::cout << "map: 2022-02-20 " << map["2022-02-19" - 1] << std::endl;
//   std::cout << "map: 2022-02-20 " << map["2022-02-19" - 2] << std::endl;
//   std::cout << "map: 2022-02-20 " << map["2022-02-19" - 3] << std::endl;
  return 0;
}
