#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4};
    for_each(v.begin(), v.end(), [](int &x) {x = x * x;});

    for (auto i : v)
        cout << i << " ";

}