#ifndef EX01_RPN_HPP_
#define EX01_RPN_HPP_

#include <string>

#define SUCCESS 0
#define ERROR 1

class RPN {
 public:
  RPN();
  ~RPN();
  int calculate(const std::string& input);

 private:
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);
  bool is_valid_token(const std::string& token);
  bool validate_input_format(const std::string& input);
};

#endif
