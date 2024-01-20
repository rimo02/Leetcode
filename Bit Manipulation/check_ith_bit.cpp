#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 5000;
    int i = 10;
    int mask = 1 << i;
    bool ans = n & mask;
    cout << "Ith bit is : " << ans; // ith bit is 1? false
}