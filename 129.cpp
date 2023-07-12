#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(string str){

    stack<int> st;
    for(int i=0;i<str.length();i++){
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            int num1=st.top();
            st.pop();
            int num2=st.top();
            st.pop();

            if(str[i]=='+'){
                st.push(num1+num2);
            }else if(str[i]=='-'){
                st.push(num1-num2);
            }else if(str[i]=='*'){
                st.push(num1*num2);
            }else if(str[i]=='/'){
                st.push(num1/num2);
            }
            
        }else{
            st.push(str[i]-'0');
        }
    }
    if(st.size()>1){
        return -1;
    }else{
        return st.top();
    }
}

int main()
{
string res="231*+9-";
cout<<solve(res);
 return 0;
}