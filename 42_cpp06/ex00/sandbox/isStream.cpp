#include <iomanip>
#include <iostream>
#include <sstream>
 
int main()
{
    std::string input = "a 41 3.14 false hello world";
    std::istringstream stream(input);
 
    char c;
    int n;
    double f;
    bool b;
 
    stream >> c >> n >> f >> std::boolalpha >> b;
    std::cout << "c = " << c << '\n'
              << "n = " << n << '\n'
              << "f = " << f << '\n'
              << "b = " << std::boolalpha << b << '\n';
 
    // extract the rest using the streambuf overload
    stream >> std::cout.rdbuf();
    std::cout << '\n';
}
