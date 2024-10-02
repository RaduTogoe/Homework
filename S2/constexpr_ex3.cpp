#include <iostream>

using namespace std;

class Fraction
{
private:
    int a, b; //    a / b
public:
    constexpr Fraction(int a, int b) : a(a), b(b) {}
    Fraction constexpr operator+(int x) const
    {
        return Fraction(a + b * x, b);
    }
    Fraction constexpr operator-(int x) const
    {
        return Fraction(a - b * x, b);
    }

    friend bool constexpr operator<(const Fraction &f1, const Fraction &f2)
    {
        int left = f1.a * f2.b;
        int right = f1.b * f2.a;

        return left < right;
    }
    friend double constexpr operator/(double nr, const Fraction &f1)
    {
        return double(f1.b / f1.a);
    }
    
};

constexpr long long int Fibonacci(int n)
{
    if (n < 2)
        return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    constexpr Fraction f1 = Fraction(Fibonacci(4), Fibonacci(5));
    constexpr Fraction f2 = f1 - Fibonacci(3);

    cout << (f1 < f2);
}