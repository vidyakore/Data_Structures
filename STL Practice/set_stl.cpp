#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(6);
    s.insert(6);

    for(auto i:s)
    {
        cout << i << endl;
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);        //deletes second element

    for(auto i:s)
    {
        cout << i << endl;
    }
    cout << endl;
    cout << "is 9 present in set: " << s.count(9);

    // cout << "6 is at position in set is: " << s.find(6);


    
}
