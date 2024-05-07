#ifndef EX01_SERIALIZER_HPP_
#define EX01_SERIALIZER_HPP_

#include <stdint.h>
#include <string>

struct Data {
  int num;
  std::string name;
};

class Serializer {
 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

 private:
  Serializer();
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& other);
  ~Serializer();
};

#endif
