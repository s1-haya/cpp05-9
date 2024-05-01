#include "random.hpp"

Base* generate() {
    int choice = std::rand() % 3;

    switch (choice) {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

void identify(Base* p) {
    A* a = dynamic_cast<A*>(p);
    if (a) {
        std::cout << "A" << std::endl;
        return;
    }

    B* b = dynamic_cast<B*>(p);
    if (b) {
        std::cout << "B" << std::endl;
        return;
    }

    C* c = dynamic_cast<C*>(p);
    if (c) {
        std::cout << "C" << std::endl;
        return;
    }

    std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        static_cast<void>(a); // Suppress unused variable warning
    } catch (std::bad_cast&) {
        // Not an A object
    }

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        static_cast<void>(b); // Suppress unused variable warning
    } catch (std::bad_cast&) {
        // Not a B object
    }

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        static_cast<void>(c); // Suppress unused variable warning
    } catch (std::bad_cast&) {
        // Not a C object
    }
}
// // main.cpp
// #include "Base.hpp"
int main() {
    std::srand(std::time(NULL));
    Base* p1 = generate();
    Base* p2 = generate();
    Base* p3 = generate();

    identify(p1);
    identify(*p2);
    identify(*p3);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
