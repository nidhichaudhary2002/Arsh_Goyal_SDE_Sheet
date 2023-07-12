#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> rem;
        int ans = 0;
        int n = nums.size();
        vector<int> prefixsum;
        prefixsum.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            prefixsum.push_back(nums[i] + prefixsum[i - 1]);
        }
        for (int i = 0; i < n; i++)
        {
            int r = prefixsum[i] % k;
            if (r == 0)
            {
                ans++;
            }
            if (r < 0)
            {
                r = k + r;
            }
            if (rem[r] != 0)
            {
                ans += rem[r];
            }
            rem[r]++;
        }
        return ans;
    }
};