#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string str;
string generate_rec(int n, int open, int close)
{
    if (open == n - 1 && open == close)
    {
        return "";
    }
    if (open < n)
    {
        // cout<<str;
        str = str + "(";
        generate_rec(n, open + 1, close);
    }
    if (close < open)
    {
        // cout<<str;
        str = str + ")";
        generate_rec(n, open, close + 1);
    }
    return str;
}
void generate(int n)
{
    int start = 0, end = 0;
    cout << generate_rec(n, start, end);
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    generate(n);
}