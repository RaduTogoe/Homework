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
    vector<int> arr = {4, 6, 3, 8, 1, 2, 5, 4, 6, 7, 9};

    vector<int> odd_numbers = {};
    copy_if(arr.begin(), arr.end(), back_inserter(odd_numbers), [](int x) -> bool{return x % 2 == 1;});

    vector<int> even_numbers = {};
    replace_copy_if(arr.begin(), arr.end(), back_inserter(even_numbers), [](int x) -> bool{return x % 2 == 1;}, 0);

    vector<int> lwr_4 = {};
    remove_copy_if(arr.begin(), arr.end(), back_inserter(lwr_4), [](int x) -> bool{return x > 4;});

    cout << odd_numbers.size();

    print(odd_numbers);
    print(even_numbers);
    print(lwr_4);
}