#include "Serializer.hpp"
#include <iostream>

uintptr_t Serializer::serialize(Data* ptr) {
  if (sizeof(Data*) > sizeof(uintptr_t)) {
    std::cerr << "Data* is too large to fit in uintptr_t" << std::endl;
    return (0);
  }
  return (reinterpret_cast<std::uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data*>(raw));
}
