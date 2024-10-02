#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_sorted_array(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

void print_sorted_array3(vector<int> arr)
{
    partial_sort(arr.begin(), arr.begin() + 3, arr.end());
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

void print_sorted_3th_elem(vector<int> arr)
{
    nth_element(arr.begin(), arr.begin() + 3, arr.end());
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {2, 4, 6, 3, 8, 5, 1};
    print_sorted_array(arr);
    print_sorted_array3(arr);
    print_sorted_3th_elem(arr);
}