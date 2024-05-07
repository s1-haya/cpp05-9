#include "Serializer.hpp"
#include <iostream>
#include <cassert>

void testTitle(const std::string title);

void testSerializer(void) {
	testTitle("test serializer & deserializer");
	// not implicit because this comile error
	// error: incompatible pointer to integer conversion assigning to 'uintptr_t' (aka 'unsigned long') from 't_data *' (aka 's_data *')
	// ptr = data;

	// not only static_cast<uintptr_t> because t_data* isn't uintptr_t.
	// error: static_cast from 't_data *' (aka 's_data *') to 'uintptr_t' (aka 'unsigned long') is not allowed
	// ptr = static_cast<uintptr_t>(data);
	Data kdot = {12, "kdot"};
    uintptr_t a = Serializer::serialize(&kdot);
    std::cout << "Unsigned int: " << a << std::endl;
    std::cout << std::endl;
    Data *god = Serializer::deserialize(a);
	testTitle("Assert check... kdot == god ??");
	assert(&kdot == god);
	assert(kdot.num == god->num);
	assert(kdot.name == god->name);

    std::cout << "Address of kdot: " << &kdot << std::endl;
    std::cout << "Name: " << kdot.name << std::endl;
    std::cout << "Num: " << kdot.num << std::endl;
    std::cout << std::endl;
    std::cout << "Address of god: " << god << std::endl;
    std::cout << "Name: " << god->name << std::endl;
    std::cout << "Num: " << god->num << std::endl;
    std::cout << std::endl;

	testTitle("Assert check... Jcole == god ??");
	god->num = 81;
	god->name = "Jcole";
	assert(&kdot == god);
	assert(kdot.num == god->num);
	assert(kdot.name == god->name);

    std::cout << "Address of Jcole: " << &kdot << std::endl;
    std::cout << "Name: " << kdot.name << std::endl;
    std::cout << "Num: " << kdot.num << std::endl;
    std::cout << std::endl;
    std::cout << "Address of god: " << god << std::endl;
    std::cout << "Name: " << god->name << std::endl;
    std::cout << "Num: " << god->num << std::endl;

}
