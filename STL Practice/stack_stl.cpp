#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<string> s;

    s.push("hi");
    s.push("my");
    s.push("love");
    // s.push(5);
    // s.push(7);

    

    s.pop();
    // s.pop();

    cout << "after popping: " << endl;
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << endl;

    cout << "top of stack is: " << s.top()<<endl;
    cout << "size of stack is: " << s.size();
}