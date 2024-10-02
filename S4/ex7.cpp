#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

void print(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 4, 6, 9, 14};
    vector<int> cummulative;

    partial_sum(v.begin(), v.end(), back_inserter(cummulative));
    print(cummulative);

    vector<int> product_range;
    partial_sum(v.begin(), v.end(), back_inserter(product_range), [](int total, int current) -> int{return total * current;});
    print(product_range);

    vector<int> difference;
    adjacent_difference(v.begin(), v.end(), back_inserter(difference));
    print(difference);
}