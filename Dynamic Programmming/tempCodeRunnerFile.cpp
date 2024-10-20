        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1), right(n + 1);
        for (int i = 0; i < (1 << n); i++)
        {
            int idx = 0, l_sum = 0, r_sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    idx++;
                    l_sum += nums[j];
                    r_sum += nums[j + n];
                }
                left[idx].push_back(l_sum);
                right[idx].push_back(r_sum);
            }
        }