#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

template <typename T>
class my_container
{
    T *elems;
    size_t length;
    size_t capacity;

public:
    my_container()
    {
        length = 0;
        capacity = 1;
        elems = new T[1];
    }

    my_container(const my_container &t)
    {
        this->length = t.length;
        elems = new T[t.capacity];
        this->capacity = t.capacity;

        for (int i = 0; i < t.size(); i++)
            elems[i] = t.elems[i];
    }

    my_container(const char *t)
    {
        length = 0;
        capacity = 1;
        elems = new T[1];
        for (int i = 0; i < strlen(t); i++)
            this->push_back(t[i]);
    }

    my_container(my_container &&t)
    {
        this->length = t.length;
        this->capacity = t.capacity;
        elems = t.elems;
        t.elems = nullptr;
    }

    my_container operator=(const my_container &t)
    {
        if (this != &t)
        {
            delete[] elems;
            elems = new T[t.capacity];
            this->size = t.length;
            this->capacity = t.capacity;

            for (int i = 0; i < t.length(); i++)
                elems[i] = t.elems[i];
        }
        return *this;
    }

    my_container operator=(my_container &&t)
    {
        if (this != &t)
        {
            delete[] elems;
            elems = t.elems;
            this->length = t.length;
            this->capacity = t.capacity;
            t.elems = nullptr;
        }
        return *this;
    }

    T operator[](int pos)
    {
        return elems[pos];
    }

    void increase_capacity()
    {
        T *placeholder = new T[capacity * 2];
        for (int i = 0; i < length; i++)
            placeholder[i] = elems[i];
        delete[] elems;
        elems = placeholder;
        capacity *= 2;
    }

    void push_back(T elem)
    {
        if (length == capacity)
            increase_capacity();
        elems[length++] = elem;
    }

    void insert(T elem, int pos)
    {
        if (length == capacity)
            increase_capacity();

        for (int i = length; i > pos; i++)
        {
            elems[i] = elems[i - 1];
        }
        elems[pos] = elem;
        length++;
    }

    void reset()
    {
        length = 0;
        capacity = 1;
        delete[] elems;
        elems = new T[capacity];
    }

    friend ostream &operator<<(ostream &COUT, my_container &m)
    {
        for (int i = 0; i < m.size(); i++)
            COUT << m[i] << " ";
        return COUT << endl;
    }

    size_t size() const
    {
        return length;
    }
};

void find_palindromes(vector<my_container<char>> &v)
{
    auto check_palindrome = [](my_container<char> str)
    {
        for (int i = 0; i < str.size() / 2; i++)
            if (str[i] != str[str.size() - i - 1])
                return false;
        return true;
    };

    auto it = find_if(v.begin(), v.end(), check_palindrome);
    
    while (it != v.end())
    {
        cout << *it << endl;
        it = find_if(next(it), v.end(), check_palindrome);
    }
}

void remove_if_not_alpha(vector<my_container<char>> &v)
{
    auto check_alpha = [](my_container<char> str)
    {
        for (int i = 0; i < str.size(); i++)
            if (!isalpha(str[i]))
                return true;
        return false;
    };

    v.erase(remove_if(v.begin(), v.end(), check_alpha), v.end());
}

int main()
{
    vector<my_container<char>> v;
    my_container<char> cont = "aaaa";
    my_container<char> cont1 = "abba";
    my_container<char> cont2 = "1234";
    my_container<char> cont3 = "123@4";
    v.push_back(cont);
    v.push_back(cont1);
    v.push_back(cont2);
    v.push_back(cont3);

    //cout << cont;
    //find_palindromes(v);

    remove_if_not_alpha(v);
    for (auto i : v)
        cout << i << endl;
}