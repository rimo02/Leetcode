#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool custom(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main()
{
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(1, 0));
    arr.push_back(make_pair(1, 1));
    arr.push_back(make_pair(0, 2));
    arr.push_back(make_pair(1, 3));
    arr.push_back(make_pair(2, 4));
    cout << "Before sorting\n"<< endl;
    for (auto ele : arr)
    {
        cout << ele.first << " " << ele.second << endl;
    }
    sort(arr.begin(), arr.end(), custom);
    cout << "After sorting\n"<< endl;
    for (auto ele : arr)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}   