#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> fact(int n)
{
    vector<int> arr;
    arr.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        int car = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            int val = i * arr[j] + car;
            arr[j] = (val % 10);
            car = val / 10;
        }
        while (car != 0)
        {
            arr.push_back(car % 10);
            car = car / 10;
        }
    }
    reverse(arr.begin(), arr.end());
    return arr;
}
int main()
{
    cout << "Enter a number: ";
    int n;
    cin >> n;
    vector<int> arr = fact(n);
    cout << "Fact= ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
}