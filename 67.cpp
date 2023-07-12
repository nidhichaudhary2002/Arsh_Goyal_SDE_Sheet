#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
            {
                cout << "carry when i =" << i << endl;
                carry += a[i--] - '0';
                cout << carry << endl;
            }
            if (j >= 0)
            {
                cout << "carry when j =" << j << endl;
                carry += b[j--] - '0';
                cout << carry<<endl;
            }

            ans += carry % 2 + '0';
            cout << ans << endl;

            carry /= 2;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }

int main()
{

cout<<addBinary("110","101");
    return 0;
}