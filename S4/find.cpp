#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_odd_elems(vector<int>::iterator begin, vector<int>::iterator end)
{
    vector<int>::iterator it = find_if(begin, end, [](int n)
            { return n % 2 == 1;});
    if (it == end)
        return;
    cout << *it << " ";
    print_odd_elems(it + 1, end);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 1, 8, 5, 2, 6, 1};
    cout << "Position of the 1st elem = 5: " << find(v.begin(), v.end(), 5) - v.begin() << endl;
    
    print_odd_elems(v.begin(), v.end());
}