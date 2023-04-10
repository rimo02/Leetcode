#include <iostream>
using namespace std;
int binomial(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    if (k == 1)
    {
        return n;
    }
    return binomial(n - 1, k - 1) + binomial(n - 1, k);
}
int binomialDP(int n, int k)
{
    int C[n + 1][k + 1];
}
int main()
{
    int n, k;
    cout << "ENter n and k: ";
    cin >> n >> k;
    cout << binomial(n, k);
}