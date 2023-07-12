#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // Gave TLE at 199 test case
        // Tried finding the breakpoint where price at ith is less than price at i+1;

        // int index=-1;
        // int cost=INT_MIN;

        // for(int i=0;i<prices.size()-1;i++){
        //     if(prices[i]<prices[i+1]){
        //         index=i;

        //         for(int j=i+1;j<prices.size();j++){
        //             if(prices[j]>prices[index]&&cost<prices[j]-prices[index]){
        //                 cost=prices[j]-prices[index];
        //             }
        //         }
        //     }
        // }

        // if(index==-1){

        //     return 0;
        // }
        // else{
        //     return cost;
        //     }

        // Using Max and min in
        // Executable
        // int n=prices.size();
        // if(n==0){
        //     return 0;
        // }
        // int minArr[n];
        // int maxArr[n];
        // minArr[0]=prices[0];
        // maxArr[n-1]=prices[n-1];

        // for(int i=1;i<n;i++){
        // minArr[i]=min(minArr[i-1],prices[i]);
        // }

        // for(int i=n-2;i>=0;i--){
        //     maxArr[i]=max(maxArr[i+1],prices[i]);
        // }

        // int cost=0;

        // for(int i=0;i<n;i++){
        // minArr[i]=maxArr[i]-minArr[i];
        // if(minArr[i]<0){
        //     minArr[i]=0;
        // }
        // }

        // for(int i=0;i<n;i++){
        //     if(minArr[i]>cost){
        //         cost=minArr[i];
        //     }
        // }

        // return cost;

        // kadance aprroach

        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};

int main()
{

    return 0;
}