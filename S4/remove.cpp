#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// remove the odd elements on even positions that end with 1
void print(vector<int> v)
{
    for_each(v.begin(), v.end(), [](int n) {cout << n << " ";});
}

vector<int> custom_remove(vector<int> v)
{
    int x = 0;
    v.erase(remove_if(v.begin(), v.end(), [&x](int n)
              { return (x++) % 2 == 0 && n % 2 == 1 && n % 10 == 1; }), v.end());
    return v;
}

int main()
{
    vector<int> v = {21, 2, 42, 3, 31, 4};
    print(custom_remove(v));
}