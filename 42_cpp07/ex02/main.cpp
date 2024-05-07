#include <iostream>

#include "whatever.hpp"

struct Data {
  int num;
  std::string name;
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
  std::cout << "--- <Data> ---" << std::endl;
  Data dataA = {12, "kdot"};
  Data dataB = {15, "drake"};
  std::cout << "dataA = " << dataA << ", dataB = " << dataB << std::endl;
  swap(dataA, dataB);
  std::cout << "dataA = " << dataA << ", dataB = " << dataB << std::endl;
  std::cout << "min( dataA, dataB ) = " << ::min(dataA, dataB) << std::endl;
  std::cout << "max( dataA, dataB ) = " << ::max(dataA, dataB) << std::endl;
  return 0;
}