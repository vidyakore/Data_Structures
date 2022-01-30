#include<iostream>
#include<stack>
#include<string>
#include<map>
using namespace std;

bool isvalid(string s)
{
    if(s.size()==1)
       return false;

    stack<char> res;
    map<char, char> dict;

    dict['('] = ')';
    dict['{'] = '}';
    dict['['] = ']';

    for (int i = 0; i < s.length();i++)
    {
        if(s[i]=='[' || s[i]=='(' || s[i]=='{')
        {
            res.push(s[i]);
        }
        else if(res.empty())
            return false;
        else
        {
            if(dict[res.top()]!=s[i])
                return false;
            res.pop();
        }
    }

    if(res.empty())
        return true;
    else
       return false;
}
int main()
{
    string s;
    cout << "Enter a string of parenthesis: ";
    cin >> s;
    cout << isvalid(s);
    return 0;
}