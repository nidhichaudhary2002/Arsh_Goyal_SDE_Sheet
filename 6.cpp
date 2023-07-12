#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        int i = mid;
        while (i <= high)
        {
            if (nums[i] == 0)
            {
                swap(nums[low], nums[i]);
                low++;
                i++;
            }
            else if (nums[i] == 1)
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[high]);
                high--;
            }
        }
    }
};

int main()
{

 return 0;
}