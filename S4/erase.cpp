#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int> v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}

vector<int> erase_first_5(vector<int> v)
{
    if (v.size() < 5)
        v.clear();
    else
        v.erase(v.begin(), v.begin() + 5);
    return v;
}

// remove even numbers
vector<int> remove_even(vector<int> v)
{
    v.erase(remove_if(v.begin(), v.end(), [](int n){return n % 2 == 0;}), v.end());
    return v;
}

int main()
{
    print(erase_first_5({1, 2, 3, 4}));
    print(remove_even({1, 2, 3, 4, 5}));
}