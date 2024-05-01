#include <iomanip>
#include <iostream>
#include <sstream>
 
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error \n";
		return (1);
	}
    std::string input = "a";
    std::istringstream stream(argv[1]);
 
    int n;
 
    stream >> n;
    std::cout << "n = " << n << '\n';
 
    // extract the rest using the streambuf overload
	if (stream.eof())
		std::cout << "eof" << std::endl;
	if (!stream.fail())
		std::cout << "success" << std::endl;
	else
		std::cout << "c failed." << std::endl;
	stream >> std::cout.rdbuf();
    std::cout << '\n';
}
