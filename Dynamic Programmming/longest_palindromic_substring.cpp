#include <iostream>
#include <vector>
#include <bits./stdc++.h>
using namespace std;
int recursion(string s, int m, int n)
{
    if (m > n)
        return INT_MAX;
    if (m == n)
        return 1;
    if (s[m] == s[n])
    {
        return 1 + recursion(s, m + 1, n - 1);
    }
}
int main()
{
    string s = "babad";
    cout << recursion(s, 0, s.length() - 1);
}