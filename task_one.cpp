#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
#include<string.h>

using namespace std;


class Solution {
public:
     stack<char> aa;
    bool isValid(string s) {
        int len=s.length();
       if (len%2 != 0)
            return false;
        char num[len+1];
        strcpy(num,s.c_str());
        for(int i = 0 ;i<=len;i++)
        {
            if(num[i]!=']' &&num[i] !='}' && num[i]!=')' )
                aa.push(num[i]);
            else if(aa.empty()&&(num[i]==']' || num[i] =='}' || num[i]==')'))
                return false;
            else if(num[i] == ']')
            {
                 if(aa.top() =='[')
                 {
                     aa.pop();
                     continue;
                 }
                else return false;
            }
                    
            else if(num[i]=='}')
            {
                 if(aa.top() =='{')

                 {
                     aa.pop();
                     continue;
                 }
                else return false;
            }
                   
            else if(num[i]==')')
            {
                 if(aa.top()=='(')
                 {
                     aa.pop();
                     continue;
                 }
                else return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution a;
    bool b=a.isValid("}{");
    cout<<b<<endl;
    
    return 0;
}