#include <iostream>

using namespace std;

class Fraction
{
public:
    constexpr Fraction(int x, int y) : a(x), b(y)
    {
    }

    constexpr Fraction add (int x) const
    {
        return Fraction(a + x * b, b);
    }
    void print() const
    {
        cout << double(a / b) << endl;
    }
private:
    int a, b;
};

int main()
{
    constexpr Fraction f(3, 4);
    constexpr Fraction f1 = f.add(5);
    f1.print();
}