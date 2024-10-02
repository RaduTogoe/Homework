#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Resource
{
    string name;

public:
    Resource(string name)
    {
        this->name = name;
        cout << "Resource created: " << name << "\n";
    }
    ~Resource()
    {
        cout << "Resource destroyed\n";
    }
    void print()
    {
        cout << "Resource name: " << name << "\n";
    }
};

template <typename T>
class SharedPtr
{
    T *value;
    int *refCount;

public:
    SharedPtr()
    {
        refCount = new int();
        *refCount = 0;
        value = nullptr;
    }

    int use_count()
    {
        if (refCount)
            return *refCount;
        return 0;
    }

    SharedPtr(T *ptr)
    {
        value = ptr;
        if (value)
            refCount = new int(1);
    }

    SharedPtr(SharedPtr &ptr)
    {
        value = ptr.value;
        refCount = ptr.refCount;

        if (value)
            (*refCount)++;
    }

    SharedPtr(SharedPtr &&ptr)
    {
        value = ptr.value;
        refCount = ptr.refCount;
        ptr.value = nullptr;
        ptr.refCount = nullptr;
    }

    ~SharedPtr()
    {
        release();
    }
    

    SharedPtr &operator=(SharedPtr &ptr)
    {
        if (this != &ptr)
        {
            release();
            value = ptr.value;
            refCount = ptr.refCount;

            if (value)
                (*refCount)++;
        }
        return *this;
    }

    SharedPtr &operator=(SharedPtr &&ptr)
    {
        if (this != &ptr)
        {
            release();
            value = ptr.value;
            refCount = ptr.refCount;
            ptr.value = nullptr;
            ptr.refCount = nullptr;
        }
        return *this;
    }

    void reset(T *ptr = nullptr)
    {
        release();
        if (ptr != nullptr)
        {
            value = ptr;
            refCount = new int(1);
        }
        else
        {
            value = nullptr;
            refCount = nullptr;
        }
    }

private:
    void release()
    {
        if (refCount)
        {
            (*refCount)--;
            if (*refCount == 0)
            {
                delete value;
                delete refCount;
            }
        }
        value = nullptr;
        refCount = nullptr;
    }
};

int main()
{
    SharedPtr<Resource> ptr2;
    {
        SharedPtr<Resource> ptr1 = new Resource("There is no moon tonight");
        ptr2 = ptr1;
        cout << ptr2.use_count() << endl;
    }
    cout << ptr2.use_count() << endl;

    shared_ptr<Resource> ptr3 = make_shared<Resource>("Hell is freezing over");
    weak_ptr<Resource> ptr = ptr3;
}