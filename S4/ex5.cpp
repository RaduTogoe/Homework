#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr = {2, 6, 4, 3, 8, 5, 1};

    partition(arr.begin(), arr.end(), [](int i) -> bool{return i % 2 == 1;});
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    //stable_partition(arr.begin(), arr.end(), [](int i) -> bool{return i % 2 == 1;});
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}