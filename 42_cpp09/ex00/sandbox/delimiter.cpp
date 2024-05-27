#include <iostream>
#include <sstream>
#include <string>

int main() {
    // 区切る文字列
    std::string str = "2010-11-11,0.24";

    // stringstreamオブジェクトを作成
    std::istringstream ss(str);

    // 結果を格納するための変数
    std::string token;

    // コンマをデリミタとして文字列を分割
    while (std::getline(ss, token, ',')) {
        std::cout << token << std::endl;
    }

    return 0;
}
