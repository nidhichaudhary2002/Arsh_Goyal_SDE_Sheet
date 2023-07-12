#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // int f(int idx,vector<int>&prices,int buy, vector<vector<int>>& dp,int n){
    //     if(idx==n){
    //         return 0;
    //     }
    // if(dp[idx][buy]!=-1){
    //     return dp[idx][buy];
    // }
    //     int profit=0;
    //     if(buy){
    //         profit=max(-prices[idx]+f(idx+1,prices,0,dp,n),0+f(idx+1,prices,1,dp,n));
    //     }else{
    //         profit=max(prices[idx]+f(idx+1,prices,1,dp,n),f(idx+1,prices,0,dp,n));
    //     }
    //     dp[idx][buy]= profit;
    //     return profit;
    // }
    //     int maxProfit(vector<int>& prices) {
    //       int n=prices.size();
    //        vector<vector<int>> dp(n,vector<int>(2,-1));
    //        return f(0,prices,1,dp,n);

    //     }

    int maxProfit(vector<int> &prices)
    {
        vector<int> ahead(2, 0), cur(2, 0);
        int n = prices.size();
        ahead[0] = ahead[1] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }
                else
                {
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                cur[buy] = profit;
            }
            ahead = cur;
        }
        return ahead[1];
    }
};