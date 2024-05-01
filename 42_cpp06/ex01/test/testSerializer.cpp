#include "Serializer.hpp"
#include <iostream>

void testTitle(const std::string title);

void testSerializer(void) {
	testTitle("test serializer");
	Data data = {12, "sawa"};
	uintptr_t ptr;
	Data* tmp;
	ptr = Serializer::serialize(&data);
	tmp = Serializer::deserialize(ptr);
	std::cout << "ptr: " << ptr;
	std::cout << std::endl;
	std::cout << "tmp: " << tmp;
	std::cout << std::endl;
	std::cout << "data: " << &data;
	std::cout << std::endl;
	// not implicit because this comile error
	// error: incompatible pointer to integer conversion assigning to 'uintptr_t' (aka 'unsigned long') from 't_data *' (aka 's_data *')
	// ptr = data;

	// not only static_cast<uintptr_t> because t_data* isn't uintptr_t.
	// error: static_cast from 't_data *' (aka 's_data *') to 'uintptr_t' (aka 'unsigned long') is not allowed
	// ptr = static_cast<uintptr_t>(data);
	Data sawa = {12, "sawa"};
    std::cout << "Address of sawa: " << &sawa << std::endl;
    std::cout << "Name: " << sawa.name << std::endl;
    std::cout << "Num: " << sawa.num << std::endl;

    uintptr_t a = Serializer::serialize(&sawa);
    std::cout << "\nUnsigned int: " << a << std::endl;

    Data *newsawa = Serializer::deserialize(a);
    std::cout << "\nAddress of newsawa: " << newsawa << std::endl;
    std::cout << "Name: " << newsawa->name << std::endl;
    std::cout << "Num: " << newsawa->num << std::endl;

	newsawa->num = 81;
    std::cout << "Address of sawa: " << &sawa << std::endl;
    std::cout << "Name: " << sawa.name << std::endl;
    std::cout << "Num: " << sawa.num << std::endl;

}
