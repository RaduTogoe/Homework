#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{
    for_each(v.begin(), v.end(), [](int n)
             { cout << n << " "; });
    cout << endl;
}

void copy_odd(vector<int> v)
{
    vector<int> cpy;
    copy_if(v.begin(), v.end(), back_inserter(cpy), [](int n)
            { return n % 2 == 1; });
}

vector<int> copy_first_4(vector<int> v)
{
    vector<int> cpy;
    copy(v.begin(), v.begin() + 4, back_inserter(cpy));
    return cpy;
}

vector<int> copy_last_4(vector<int> v)
{
    vector<int> cpy;
    copy(v.end() - 4, v.end(), back_inserter(cpy));
    return cpy;
}

vector<int> copy_middle(vector<int> v)
{
    vector<int> cpy;
    copy(v.begin() + 1, v.end() - 1, back_inserter(cpy));
    return cpy;
}

vector<int> copy_first4_dif_2(vector<int> v)
{
    vector<int> cpy;
    copy_if(v.begin(), v.end(), back_inserter(cpy), [](int n)
            { return n != 2; });
    if (cpy.size() >= 4)
        cpy = copy_first_4(cpy);
    return cpy;
}

vector<int> copy_last4_multiple3(vector<int> v)
{
    vector<int> cpy;
    copy_if(v.begin(), v.end(), back_inserter(cpy), [](int n)
            { return n % 3 == 0; });
    if (cpy.size() >= 4)
        cpy = copy_last_4(cpy);
    return cpy;
}

vector<int> copy_middle_div5(vector<int> v)
{
    vector<int> cpy;
    copy_if(v.begin(), v.end(), back_inserter(cpy), [](int n)
            { return n % 5 == 0; });
    if (cpy.size() > 2)
        cpy = copy_middle(cpy);
    return cpy;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
    print(copy_middle_div5(v));
}