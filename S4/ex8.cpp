#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int increase()
{
    static int i = 0;
    return i++;
}

int main()
{
    vector<int> arr = {4, 6, 3, 8, 1};
    /*
    rotate(arr.begin(), arr.begin() + 1, arr.end());
    print(arr);

    vector<int> reversed_arr;
    reverse_copy(arr.begin(), arr.end(), back_inserter(reversed_arr));
    print(reversed_arr);

    vector<int> generated_arr(10);
    generate(generated_arr.begin(), generated_arr.end(), increase);
    print(generated_arr);

    vector<int> square_arr;
    transform(arr.begin(), arr.end(), back_inserter(square_arr), [](int x) {return x * x;});
    print(square_arr);*/

    vector<int> square_root_arr;
    transform(arr.begin(), arr.end(), back_inserter(square_root_arr), [](int x) {return sqrt(x);});
    print(square_root_arr);
}