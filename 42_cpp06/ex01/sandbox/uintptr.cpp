#include <cstdint>
#include <iostream>

struct Data
{
	int i;
	std::string name;
};

uintptr_t serialize(Data* ptr)
{
	if (sizeof(Data*) > sizeof(uintptr_t)) {
		std::cerr << "Data* is too large to fit in uintptr_t" << std::endl;
		return (0);
	}
	return (reinterpret_cast<std::uintptr_t>(ptr));
	// return (static_cast<std::uintptr_t>(reinterpret_cast<void*>(ptr)));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data data = {12, "sawa"};
	uintptr_t ptr;
	Data* tmp;
	// not implicit because this comile error

	// error: incompatible pointer to integer conversion assigning to 'uintptr_t' (aka 'unsigned long') from 't_data *' (aka 's_data *')
	// ptr = data;

	// not only static_cast<uintptr_t> because t_data* isn't uintptr_t.
	// error: static_cast from 't_data *' (aka 's_data *') to 'uintptr_t' (aka 'unsigned long') is not allowed
	// ptr = static_cast<uintptr_t>(data);

	ptr = serialize(&data);
	tmp = deserialize(ptr);
	std::cout << "ptr: " << ptr;
	std::cout << std::endl;
	std::cout << "tmp: " << tmp;
	std::cout << std::endl;
	std::cout << "data: " << &data;
	std::cout << std::endl;
}
