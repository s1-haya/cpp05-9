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
    std::string input = argv[1];

	//f failed
    // std::string input = "a";
    // std::string input = " a";
    // std::string input = "a   ";
    // std::string input = "a  b";
	if (input[input.length() - 1] == 'f')
    	input = input.erase(input.length() - 1);
    std::istringstream stream(input);
 
    float f;
 
    stream >> f;
    std::cout << "f = " << f << '\n';
 
    // extract the rest using the streambuf overload
	if (stream.eof())
		std::cout << "eof" << std::endl;
	if (!stream.fail())
		std::cout << "success" << std::endl;
	else
		std::cout << "f failed." << std::endl;
	stream >> std::cout.rdbuf();
    std::cout << '\n';
}
