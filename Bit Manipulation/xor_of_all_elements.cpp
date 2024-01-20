#include <iostream>
#include <vector>
using namespace std;
int xorfind(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
}
int main()
{
    int n = 5;
    int l = 0, r = 20;
    int out = xorfind(l) ^ xorfind(r - 1);
    cout << out << endl;
}