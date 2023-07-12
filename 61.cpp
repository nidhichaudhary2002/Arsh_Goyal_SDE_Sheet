#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {

        vector<vector<char>> ans = mat;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 or j == 0 or j == m - 1 or i == n - 1)
                {
                    if (mat[i][j] == 'O')
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<int> delx = {-1, 0, 1, 0};
            vector<int> dely = {0, -1, 0, 1};
            for (int i = 0; i < 4; i++)
            {
                int nx = row + delx[i];
                int ny = col + dely[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] == 'O' && !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ans[i][j] == 'O' && !vis[i][j])
                {
                    ans[i][j] = 'X';
                }
            }
        }
        return ans;
    }
};