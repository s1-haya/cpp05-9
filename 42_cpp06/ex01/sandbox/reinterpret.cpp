#include <iostream>

class A {
 public:
  int a;
  A() : a(0) {}
};

class B : public A {

 public:
  int b, c;
  B() : b(0), c(0) {}
};

void use_of_reinterpret_cast() {
  A a1;
  std::cout << "a1.p: " << &a1 << std::endl;
  std::cout << "a1.a: " << a1.a << std::endl;
  long l = reinterpret_cast<long>(&a1);
  // safe
  A* ap = reinterpret_cast<A*>(l); 
  std::cout << "ap.p: " << ap << std::endl;
  std::cout << "ap.a: " << ap->a << std::endl;

  //unsafe
  B* bp = reinterpret_cast<B*>(&a1);
  std::cout << "bp.p: " << bp << std::endl;
  std::cout << "bp.a: " << bp->a << std::endl;
  std::cout << "bp.b: " << bp->b << std::endl;
  std::cout << "bp.c: " << bp->c << std::endl;
  //    const A a2;
  //    ap = reinterpret_cast<A*>(&a2);  // error, const removed
}

int main(void) {
  use_of_reinterpret_cast();
  return 0;
}
