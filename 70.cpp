#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int square(int n)
{
    int num = 0;
    while (n > 10)
    {
        num += pow(n % 10, 2);
        n = n / 10;
    }
    num += pow(n % 10, 2);

    return num;
}

void isHappy(int n)
{

    if (n == 1)
    {
        cout << "true";
    }
    unordered_map<int, bool> map;

    while (map.count(n) == 0)
    {
        map[n] = true;
        cout << n << endl;
        n = square(n);
    }

    if (n == 1)
    {
        cout << "true";
    }

    cout << "false";
}

int main()
{
    cout << square(23);
    isHappy(23);
}
