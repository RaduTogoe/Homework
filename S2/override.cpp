
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function\n";
    }
};

class Derived : public Base {
public:
    // Incorrectly typed function; no override (missing 'override')
    void show(int) {  // Different signature, doesn't override
        std::cout << "Derived class show function with int parameter\n";
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->show();  // Calls Base::show because Derived::show(int) doesn't override Base::show()
    
    delete basePtr;
    return 0;
}
