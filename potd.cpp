#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void mapping(unordered_map<TreeNode *, TreeNode *> &mp, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left != NULL)
        {
            mp[root->left] = root;
        }

        if (root->right != NULL)
        {
            mp[root->right] = root;
        }
            mapping(mp, root->left);
            mapping(mp, root->right);
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        unordered_map<TreeNode *, TreeNode *> mp;
        unordered_map<int, bool> visited;

        mapping(mp, root);

        queue<TreeNode *> q;
        q.push(target);
        visited[target->val] = true;

        while (!q.empty())
        {
            if (k == 0)
            {
                break;
            }

            TreeNode *curr = q.front();
            q.pop();

            if (curr->left != NULL && visited.count(curr->left->val) == 0)
            {
                visited[curr->left->val] = true;
                q.push(curr->left);
            }

            if (curr->right != NULL && visited.count(curr->right->val) == 0)
            {
                visited[curr->right->val] = true;
                q.push(curr->right);
            }

            if (mp.count(curr) != 0 && visited.count(mp[curr]->val) == 0)
            {
                visited[mp[curr]->val] = true;
                q.push(mp[curr]);
            }
            k--;
        }

        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};