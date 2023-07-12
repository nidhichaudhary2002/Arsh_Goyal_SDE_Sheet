#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        queue<int> q;
        for (int i = 0; i < arr.size(); i++)
        {
            q.push(arr[i]);
        }
        int ans = 0;

        while (q.size() != 1)
        {
            int num1 = q.front();
            q.pop();
            int num2 = q.front();
            q.pop();
            ans += num1 * num2;
            q.push(max(num1, num2));
        }

        return ans;
    }
};
int main()
{

    return 0;
}