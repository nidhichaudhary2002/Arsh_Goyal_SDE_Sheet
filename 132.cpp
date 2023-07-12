#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.

    bool ispossible(vector<vector<int>> grid, int i, int j, int n, int m, vector<vector<bool>> visited)
    {
        return i < n && i >= 0 && j < m && j >= 0 && !visited[i][j];
    }

    int bfs(vector<vector<int>> grid, int i, int j, int n, int m)
    {
         vector<vector<bool>> visited(n, vector<bool>(m,false));
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            if (grid[r][c] == 1)
            {
                return abs(i - r) + abs(j - c);
            }

            for (int i = 0; i < 4; i++)
            {
                int newR = r + row[i];
                int newC = c + col[i];
                if (ispossible(grid, newR, newC, n, m, visited))
                {
                    q.push({newR, newC});
                    visited[newR][newC] = true;
                }
            }
        }

        return -1;
    }

    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

      
       
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {       if(grid[i][j]==0){
                
                    int a = bfs(grid, i, j, n, m);
                    ans[i][j] = a;
            }else{
                ans[i][j]=0;
            }
            }
        }

        return ans;
    }
};