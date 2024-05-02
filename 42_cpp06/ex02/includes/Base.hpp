#ifndef EX02_BASE_HPP_
#define EX02_BASE_HPP_

class Base {
//  protected:
//   Base();

 public:
  virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
