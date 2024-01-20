#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1, -2, -3, -4, 5, 6};
    int n = nums.size();
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    prefix[0] = 1;
    suffix[n - 1] = 1;
    for (int i = 0; i < n; i++)
    {
        
    }
}
