

// C++ program to convert string 
// to char array using c_str() 
#include <cstring> 
#include <string> 
#include <iostream> 
  
// driver code 
int main() 
{ 
    // assigning value to string s 
    std::string s = "geeksforgeeks"; 
  
    const int length = s.length(); 
  
    // declaring character array (+1 for null terminator) 
    char* char_array = new char[length + 1]; 
  
    // copying the contents of the 
    // string to char array 
	std::cout << "char: " << s.c_str() << std::endl; 
    strcpy(char_array, s.c_str()); 
  
    for (int i = 0; i < length; i++) 
    { 
        std::cout << "char: " << char_array[i] << std::endl; 
    } 
    
    delete[] char_array; 
    
    return 0; 
}
