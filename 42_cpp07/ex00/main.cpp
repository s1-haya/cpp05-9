#include <iostream>

#include "whatever.hpp"

enum Type { A, B };

struct Data {
  int num;
  std::string name;

  Data(int n, const std::string& s) : num(n), name(s) {}

  Data(const Data& other) : num(other.num), name(other.name) {}

  Data& operator=(const Data& other) {
    num = other.num;
    name = other.name;
    return *this;
  }
  bool operator<(const Data& other) const {
    if (num != other.num) {
      return num < other.num;
    } else {
      return name < other.name;
    }
  }

  bool operator>(const Data& other) const { return other < *this; }
};

int main(void) {
  std::cout << "--- <int> ---" << std::endl;
  int intA = 2;
  int intB = 3;
  std::cout << "intA = " << intA << ", intB = " << intB << std::endl;
  swap(intA, intB);
  std::cout << "intA = " << intA << ", intB = " << intB << std::endl;
  std::cout << "min( intA, intB ) = " << ::min(intA, intB) << std::endl;
  std::cout << "max( intA, intB ) = " << ::max(intA, intB) << std::endl;
  std::cout << "--- <std::string> ---" << std::endl;
  std::string stringA = "chaine1";
  std::string stringB = "chaine2";
  std::cout << "stringA = " << stringA << ", stringB = " << stringB
            << std::endl;
  swap(stringA, stringB);
  std::cout << "stringA = " << stringA << ", stringB = " << stringB
            << std::endl;
  std::cout << "min( stringA, stringB ) = " << ::min(stringA, stringB)
            << std::endl;
  std::cout << "max( stringA, stringB ) = " << ::max(stringA, stringB)
            << std::endl;
  std::cout << "--- <float> ---" << std::endl;
  float floatA = 1.2;
  float floatB = 1.4;
  std::cout << "floatA = " << floatA << ", floatB = " << floatB << std::endl;
  swap(floatA, floatB);
  std::cout << "floatA = " << floatA << ", floatB = " << floatB << std::endl;
  std::cout << "min( floatA, floatB ) = " << ::min(floatA, floatB) << std::endl;
  std::cout << "max( floatA, floatB ) = " << ::max(floatA, floatB) << std::endl;
  std::cout << "--- <Type> ---" << std::endl;
  Type typeA = A;
  Type typeB = B;
  std::cout << "typeA = " << typeA << ", typeB = " << typeB << std::endl;
  swap(typeA, typeB);
  std::cout << "typeA = " << typeA << ", typeB = " << typeB << std::endl;
  std::cout << "min( typeA, typeB ) = " << ::min(typeA, typeB) << std::endl;
  std::cout << "max( typeA, typeB ) = " << ::max(typeA, typeB) << std::endl;
  std::cout << "--- <Pointer> ---" << std::endl;
  const char* pointerA = "a";
  const char* pointerB = "b";
  std::cout << "pointerA = " << pointerA << ", pointerB = " << pointerB
            << std::endl;
  swap(pointerA, pointerB);
  std::cout << "pointerA = " << pointerA << ", pointerB = " << pointerB
            << std::endl;
  std::cout << "min( pointerA, pointerB ) = " << ::min(pointerA, pointerB)
            << std::endl;
  std::cout << "max( pointerA, pointerB ) = " << ::max(pointerA, pointerB)
            << std::endl;
  std::cout << "--- <Data> ---" << std::endl;
  Data dataA(1985, "Jcole");
  Data dataB(1986, "drake");
  std::cout << "dataA = " << dataA.name << "," << dataA.num << std::endl;
  std::cout << "dataB = " << dataB.name << "," << dataB.num << std::endl;
  std::cout << "dataA = " << dataA.name << "," << dataA.num << std::endl;
  std::cout << "dataB = " << dataB.name << "," << dataB.num << std::endl;
  swap(dataA, dataB);
  std::cout << "dataA = " << dataA.name << "," << dataA.num
            << " dataB = " << dataB.name << std::cout
            << "dataA = " << dataA.name << ", dataB = " << dataB.name
            << std::endl;
  std::cout << "dataA = " << dataA.num << ", dataB = " << dataB.num
            << std::endl;
  std::cout << "min( dataA, dataB ) = " << ::min(dataA, dataB).name
            << std::endl;
  std::cout << "max( dataA, dataB ) = " << ::max(dataA, dataB).name
            << std::endl;
  return (0);
}
