#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the number of islands.

    bool isSafe(vector<vector<bool>> &visited, vector<vector<char>> &grid, int row, int col)
    {

        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && !visited[row][col];
    }

    void bfs(vector<vector<bool>> &visited, vector<vector<char>> &grid, int row, int col)
    {

        int ra[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int ca[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            int r = curr.first;
            int c = curr.second;
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int newR = r + ra[i];
                int newC = c + ca[i];

                if (isSafe(visited, grid, newR, newC) && grid[newR][newC] == '1')
                {
                    visited[newR][newC] = true;
                    q.push({newR, newC});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        // Code here

        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    bfs(visited, grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};