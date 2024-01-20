#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {1, -2, 3, -4, 5, -3, -2};
    int k = 7;
    set<int> st;
    int sum = 0;
    int ans = INT16_MIN;
    for (auto num : nums)
    {
        sum += num;
        auto it = st.lower_bound(sum - k);
        if (it != st.end())
        {
            ans = max(ans, sum - *it);
        }
        st.insert(sum);
    }
    cout << ans;
}