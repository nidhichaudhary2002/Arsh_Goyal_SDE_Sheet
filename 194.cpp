#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(0);

        visited[0] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (auto it : adj[curr])
            {
                if (!visited[it])
                {
                    q.push(adj[curr][it]);
                    visited[it] = true;
                }
            }
        }

        return ans;
    }
};

int main()
{
int v=4;
vector<int > adj[4];

adj[0]={1,2,3};
adj[1]={0};
adj[2]={4};
adj[3]={0};



    return 0;
}