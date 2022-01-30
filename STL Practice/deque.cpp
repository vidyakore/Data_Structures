#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);

    cout << "show deque: " << endl;
    for(int i:d){
        cout << i<<endl;
    }
    cout << "show deque using size in for loop: \n";
    for (int i = 0; i < d.size();i++)
        cout << d[i]<<endl;

    d.pop_back();
    d.pop_front();

    cout << "show deque after popping: " << endl;
    for(int i:d){
        cout << i<<endl;
    }

    cout << "element at 1st position: " << d.at(0) << endl;

}