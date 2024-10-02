#include <iostream>
#include <memory>
using namespace std;

class Resource
{
    string name;
public:
    Resource(const string& name)
    {
        cout << "Resource allocated: " << name << "\n";
        this->name = name;
    }
    ~Resource()
    {
        cout << "Resource deallocated: " << name << "\n";
    }
    void print()
    {
        cout << "Resource name: " << name << "\n";
    }

    friend ostream &operator<<(ostream &COUT, Resource r)
    {
       return cout << "Resource name: " << r.name << "\n";
    }
};

template<typename T>
class UniquePtr
{
    T *value;
public:
    UniquePtr()
    {
        value = nullptr;
    }
    UniquePtr(T *x)
    {
        value = x;
    }
    UniquePtr(const UniquePtr &&x)
    {
        if (value)
            delete value;

        value = x.value;
        x.value = nullptr;
        return *this;
    }
    UniquePtr operator=(UniquePtr &&x)
    {
        if (value)
            delete value;

        value = x.value;
        x.value = nullptr;
        return *this;
    }
    UniquePtr operator=(UniquePtr &x) = delete;
    UniquePtr(UniquePtr &x) = delete;
    ~UniquePtr()
    {
        delete value;
    }

    inline void reset(T *x = nullptr)
    {
        if (value)
            delete value;
        value = x;
    }

    operator bool() const {
        return value != nullptr;
    }

    T& operator*() const {return *value};
    T* operator->() const {return value};
};

int main()
{
    UniquePtr<Resource> p1 = new Resource("ptr1");
    p1->print();
    cout << *p1;
}