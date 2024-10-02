#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_odd_numbers(vector<int> v)
{
    return count_if(v.begin(), v.end(), [](int x) -> bool{return x % 2 == 1;});
}

auto search_word(string str, string word)
{
    return search(str.begin(), str.end(), word.begin(), word.end());
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    string s = "the quick brown fox jumps over the lazy dog";
    cout << "The array has " << count_odd_numbers(v) << " odd elements.\n";
    cout << "fox: " << *search_word(s, "fox") << endl;
    cout << "fox: " << *search_word(s, "dog") << endl;
    cout << "fox: " << *search_word(s, "bear") << endl;
}