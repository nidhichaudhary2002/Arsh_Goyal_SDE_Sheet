#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.

    string checkWithSizeN(string s, string p, int n)
    {
        unordered_map<char, int> mp;
        string ans;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]] = i;
            ans += s[i];
        }

        bool found = true;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(p[i]) < 0)
            {
                found = false;
                break;
            }
        }
        found = true;
        if (found)
        {
            return ans;
        }

        for (int j = n; j < s.size(); j++)
        {

            auto it = mp.find(s[j - n]);
            mp.erase(it);
            mp[s[j]] = j;
            ans.erase(0, 1);
            ans += s[j];
            found = true;

            for (int i = 0; i < n; i++)
            {
                if (mp.count(p[i]) < 0)
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return ans;
            }
        }

        return "-1";
    }

    string smallestWindow(string s, string p)
    {
        // Your code here
        int n = p.size();

        for (int i = n; i < s.length(); i++)
        {
            string ans = checkWithSizeN(s, p, i);
            if (ans != "-1")
            {
                return ans;
            }
        }
        return "-1";
    }
};