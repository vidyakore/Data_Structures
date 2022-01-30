#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<string> q;

    q.push("hi");
    q.push("chery");
    q.push("strawberry");

    cout << "before pop size is: " << q.size()<<endl;
    cout << "before pop front is: "<<q.front();
    

    q.pop();
    cout << "after pop size is: " << q.size()<<endl;
    cout << "after pop front is: " << q.front();
}
