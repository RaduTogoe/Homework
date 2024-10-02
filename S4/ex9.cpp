#include <bits/stdc++.h>

using namespace std;

template<typename T>
double constexpr harmonic_media(T v)
{
    int n = v.size();
    double media = 0.0;
    for (auto i : v)
        media += 1.0 / i;
    return n / media;
}

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
        return double(f1.b) / f1.a;
    }
    
};

int main()
{
    vector<Fraction> v;
    v.push_back(Fraction(1,2));
    v.push_back(Fraction(3,4));
    v.push_back(Fraction(5,6));

    cout << harmonic_media(v);
}