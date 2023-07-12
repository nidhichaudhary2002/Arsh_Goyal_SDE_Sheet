#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool testPalindrome(const string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] == s[j])
            {
                ++i;
                --j;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;

        int cnt = 0;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
                continue;
            }
            else
            {
                return testPalindrome(s, i + 1, j) || testPalindrome(s, i, j - 1);
            }
        }
        return true;
    }
};