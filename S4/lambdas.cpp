#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    auto sum = [](int a, int b) {return a + b;};
    auto is_odd = [](int x) {return x % 2 == 1;};

    auto print = [is_odd](int x) {cout << is_odd(x) << " ";};
    vector<int> v = {4, 2, 3, 4, 1};
    for_each(v.begin(), v.end(), print);
}