#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
bool isOperator(string s, int idx)
{
    if (s[idx] == '+' || s[idx] == '*' || s[idx] == '/' || s[idx] == '-')
    {
        return true;
    }
    return false;
}

void calculate(string s)
{

    queue<int> q;
    queue<char> oper;

    for (int i = 0; i < s.length(); i++)
    {

        if (isOperator(s, i))
        {
            oper.push(s[i]);
            cout<<"true"<<endl;
        }
        else
        {
            string temp;
            while (i < s.length() && !isOperator(s, i))
            {
                temp += s[i];
                i++;
            }
            int j = stoi(temp);
            q.push(j);
            cout<<j<<endl;
        }
    }

    while (q.size() > 1)
    {
        int a = q.front();
        q.pop();
        int b = q.front();
        q.pop();

        if (oper.front() == '+')
        {
            q.push(a + b);
            oper.pop();
        }
        else if (oper.front() == '-')
        {
            q.push(a - b);
            oper.pop();
        }
        else if (oper.front() == '*')
        {
            q.push(a * b);
            oper.pop();
        }
        else
        {
            oper.push(a / b);
            oper.pop();
        }
    }
    while(!oper.empty()){
        cout<<oper.front();
        oper.pop();
    }
    cout<<"Ans : " <<q.front();
}
// };

int main()
{

    string s = "1+2";
    // int i =stoi(s);

    calculate(s);
}