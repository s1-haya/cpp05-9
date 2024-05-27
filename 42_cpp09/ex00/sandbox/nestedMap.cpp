#include <iostream>
#include <map>
#include <sstream>
#include <string>

typedef std::map<int, float> DayData;
typedef std::map<int, DayData> MonthData;
typedef std::map<int, MonthData> YearData;

void addData(YearData& map, const std::string& line) {
    int year, month, day;
	float value;
    char dash;
    std::istringstream stream(line);
    stream >> year >> dash >> month >> dash >> day >> dash >> value;
    map[year][month][day] = value;
}

void printData(const YearData& data) {
    for (YearData::const_iterator yearIt = data.begin(); yearIt != data.end(); ++yearIt) {
        std::cout << "Year: " << yearIt->first << std::endl;
        for (MonthData::const_iterator monthIt = yearIt->second.begin(); monthIt != yearIt->second.end(); ++monthIt) {
            std::cout << "  Month: " << monthIt->first << std::endl;
            for (DayData::const_iterator dayIt = monthIt->second.begin(); dayIt != monthIt->second.end(); ++dayIt) {
                std::cout << "    Day: " << dayIt->first << " - Value: " << dayIt->second << std::endl;
            }
        }
    }
}

// int main() {
//     YearData data;
//     addData(data, "2022-02-20,123.45");
//     addData(data, "2022-02-23,125.45");
//     printData(data);
//     return 0;
// }
