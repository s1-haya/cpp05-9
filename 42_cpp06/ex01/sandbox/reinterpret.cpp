#include <cstdint>

class A {int a; public: A();};
class B: public A {int b, c;};

void use_of_reinterpret_cast()
{
     A a1;
     long l = reinterpret_cast<long>(&a1);
     A* ap = reinterpret_cast<A*>(l);      // safe
    //  B* bp = reinterpret_cast<B*>(&a1);    // unsafe
    //  const A a2;
    //  ap = reinterpret_cast<A*>(&a2);  // error, const removed
}
