#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
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

  std::map<std::string, std::string> map;
  std::string line;
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string key, value;
    if (std::getline(ss, key, ',') && std::getline(ss, value, ',')) {
      map[key] = value;
    }
  }

  std::map<std::string, std::string>::iterator it = map.begin();
  while (it != map.end()) {
    std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
    ++it;
  }
  return 0;
}
