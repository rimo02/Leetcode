#include <iostream>
using namespace std;
int jump(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    return jump(n - 1) + jump(n - 2) + jump(n - 3);
}
int main()
{
    cout << "Enter n:";
    int n;
    cin >> n;
    cout << "Possible jumps=" << jump(n);
}