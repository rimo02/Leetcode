#include <bits/stdc++.h>
using namespace std;
long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        long long gc = gcd(a, b);
        if (gc == a)
        {
            cout <<max( b * 2 , a*b) << endl;
        }
        else
        {
            cout << (a * b)/gc << endl;
        }
    }
}