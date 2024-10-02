#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

void print(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << accumulate(v.begin(), v.end(), 0, [](int total, int next) -> int{return total + next * next;});
}