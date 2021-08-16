#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool  isValid(string s) 
{
    
    stack<char> mystack;
    
    for (int i=0;i<s.length();i++)
    {
        
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            mystack.push(s[i]);
        
        else if(mystack.empty())
            return false;
            
        else
        {
            if (mystack.top()=='(' && s[i] == ')')
                mystack.pop();
            
            
            else if (mystack.top()=='[' &&  s[i] == ']')
                mystack.pop();
                
            else if (mystack.top()=='{' && s[i] == '}')
                mystack.pop();
            else
                return false;
        }
            
        
    }
    if (mystack.empty())
        return true;
    
    else
        return false;
     
    }
int main()
{
    cout<<isValid("{[]()[]}");

    return 0;
}