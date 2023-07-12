#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         vector<vector<int>> finalAns;
//         int i=0;
//         while(i<n-2){
//             if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
//             int j=i+1,k=n-1;
//             int target=0-nums[i];
//             while(j<k){
//                 if(nums[j]+nums[k]==target){
//                     vector<int> ans={nums[i],nums[j],nums[k]};
//                     finalAns.push_back(ans);
//                 while(nums[j]==nums[j+1]&&j<k){
//                     j++;
//                 }
//                 while(nums[k]==nums[k-1]&&k>j){
//                     k--;
//                 }
//                     j++;
//                     k--;
//                 }else if(nums[j]+nums[k]<target){
//                     j++;
//                 }else{
//                     k--;
//                 }

//             }}
//             i++;
//         }

// return finalAns;

 vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                     
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
};

int main()
{

 return 0;
}