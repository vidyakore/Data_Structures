#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //max heap
    priority_queue<int> maxh;                           

    //min heap
    priority_queue<int,vector<int>, greater<int>> minh;

    maxh.push(1);
    maxh.push(3);
    maxh.push(10);
    maxh.push(15);

    cout << "maxh size-> " << maxh.size() << endl;
    int n = maxh.size();
    for (int i = 0; i < n;i++)
    {
        cout << maxh.top() << " ";
        maxh.pop();
    }
    cout << endl;

    minh.push(5);
    minh.push(7);
    minh.push(0);
    minh.push(19);
    minh.push(32);
    cout << "minh size-> " << minh.size() << endl;
    int m = minh.size();
    for (int i = 0; i < m;i++)
    {
        cout << minh.top() << " ";
        minh.pop();
    }
    cout << endl;
} 