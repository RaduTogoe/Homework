#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
[[deprecated("function sum() uses STL vectors")]]
int sum(int *v, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i];
    return sum;
}   

int sum(vector<int> v)
{
    return accumulate(v.begin(), v.end(), 0);
}

int main()
{
    int v[] = {1, 2, 3, 4};
    int n = 4;
    vector<int> v1 = {1, 2, 3, 4};
    cout << sum(v1);
}