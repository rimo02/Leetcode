#include <iostream>
using namespace std;
int countSetBits(int n)
{
    int count = 0;
    int i = 1;
    while (n > 0)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int main()
{
    int a = 20;
    int b = 10;
    cout << countSetBits(a ^ b);
}