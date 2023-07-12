#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMinChocolate(int *arr,int n, int m){
    sort(arr,arr+n);
int ans=INT_MAX;
    for(int i=0;i+m-1<n;i++){
            ans=min(arr[i+m-1]-arr[i],ans);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
int *arr=new int[n];

for(int i=0;i<n;i++){
    cin>>arr[i];
}

int m;
cin>>m;
cout<<findMinChocolate(arr,n,m);

 return 0;
}