#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans(2);
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            int y = target - x;
            if (mp.find(y) != mp.end())
            {
                ans[0] = i;
                ans[1] = mp[y];
                break;
            }
            mp[x] = i;
        }
        return ans;
    }
};