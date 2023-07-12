#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> ans;
    int n = nums1.size();
    int m = nums2.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        mp[nums2[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {

        int j = mp[nums1[i]];
        int ele = nums2[j];
        int cmp=ele;

        // cout << ele<<endl;

        while (j < m)
        {
            if (nums2[j] > ele)
            {
                ele = nums2[j];
                break;
            }
            j++;
        }

        if (ele == cmp)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(ele);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
 
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
}