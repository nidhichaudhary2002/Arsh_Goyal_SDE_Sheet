#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reachable = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (reachable < i)
            {
                return false;
            }
            reachable = max(reachable, nums[i] + i);
        }
        return true;
    }
};