#include <iostream>

using namespace std;

constexpr long long int fibo(int n)
{
    if (n < 2)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

long long int fibo1(int n)
{
    if (n < 2)
        return n;
    return fibo1(n - 1) + fibo1(n - 2);
}

int main()
{
    const long long int a = fibo(45);
    cout << a;
}