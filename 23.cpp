#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ans;
    
    bool isValid(int i, int j, int n, int m, int idx, string word, vector<vector<bool>>& vis, vector<vector<char>>& a)
    {
        return ((i >= 0) and (i < n) and (j >= 0) and (j < m) and (idx < word.size()) and (!vis[i][j]) and (word[idx] == a[i][j]));
    }
    
    void dfs(vector<vector<char>>& a, vector<vector<bool>>& vis, int i, int j, string word, int n, int m, int idx)
    {
        vis[i][j] = true;
        if(idx == (-1 + word.size()) and word[idx] == a[i][j])
        {
            ans = true;
            return;
        }
        if(isValid(i+1, j, n, m, idx + 1, word, vis, a))
        {
            dfs(a, vis, i+1, j, word, n, m, idx + 1);
        }
        if(isValid(i-1, j, n, m, idx + 1, word, vis, a))
        {
            dfs(a, vis, i-1, j, word, n, m, idx + 1);
        }
        if(isValid(i, j+1, n, m, idx + 1, word, vis, a))
        {
            dfs(a, vis, i, j+1, word, n, m, idx + 1);
        }
        if(isValid(i, j-1, n, m, idx + 1, word, vis, a))
        {
            dfs(a, vis, i, j-1, word, n, m, idx + 1);
        }
        vis[i][j] = false;
    }
    
    bool exist(vector<vector<char>>& a, string word) {
        int i, j, n = a.size(), m = a[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        ans = false;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(ans)
                {
                    return true;
                }
                if(a[i][j] == word[0])
                {
                    dfs(a, vis, i, j, word, n, m, 0);
                }
            }
        }
        return ans;
    }
};