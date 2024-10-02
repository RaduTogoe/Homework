#include <iostream>

using namespace std;

class Base
{
public:
    virtual void fun() {cout << "Base" << endl;}
};

class D1 : public Base
{
public:
    virtual void fun() final {cout << "D1\n";}
    virtual void over() {cout << "OVERD1\n";}
};

class D2 final : public D1
{ 
public:
    virtual void over() override {cout << "OVERD2";} 
};

//class D3 : D2 ----  D2 is final and cant be a base class

int main()
{

}