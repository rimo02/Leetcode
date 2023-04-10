#include <iostream>
using namespace std;
bool sub_sum(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (set[n - 1] > sum)
        return sub_sum(set, n - 1, sum);
    return sub_sum(set, n - 1, sum - set[n - 1]) || sub_sum(set, n - 1, sum);
}
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = 6;
    int sum = 10;
    if (sub_sum(set, n, sum) == false)
    {
        cout << "No solution exist";
    }
    else
    {
        cout << "Solution exist";
    }
}