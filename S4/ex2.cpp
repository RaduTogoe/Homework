#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

void check_all(vector<int> arr)
{
    if (all_of(arr.begin(), arr.end(), [](int i) -> bool{return i % 2 == 0;}))
        cout << "All elements are even" << endl;
    else if (all_of(arr.begin(), arr.end(), [](int i) -> bool{return i % 2 == 1;}))
        cout << "All elements are odd" << endl;
    else
        cout << "There are both odd and even elements";
}

void check_any(vector<int> arr)
{
    if (any_of(arr.begin(), arr.end(), [](int i) -> bool{return i % 2 == 1;}))
        cout << "Some elements are odd " << endl;
    else
        cout << "All elements are even";
}

void find_greater_than_7(vector<int> arr)
{
    auto elem = find_if(arr.begin(), arr.end(), [](int x) -> bool{return x > 7;});
    cout << "First elem greater than 7 is: " << *elem << endl;
}



int main()
{
    vector<int> arr = {1,2,3,7,3,9,4,8,6,3};
    find_greater_than_7(arr);
}