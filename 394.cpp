#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {

        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ']')
            {

                string temp = "";
                while (!st.empty() && st.top() >= 'a' && st.top() <= 'z')
                {
                    temp += st.top();
                    st.pop();
                }

                reverse(temp.begin(), temp.end());
                st.pop();

                string temp2 = "";
                while (!st.empty() && st.top() >= '0' && st.top() <= '9')
                {
                    temp2 += st.top();
                    st.pop();
                }

                reverse(temp2.begin(), temp2.end());
                int x = stoi(temp2);

                temp2 = temp;
                x--;
                while (x--)
                {
                    temp += temp2;
                }

                for (int k = 0; k < temp.length(); k++)
                {
                    st.push(temp[k]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};