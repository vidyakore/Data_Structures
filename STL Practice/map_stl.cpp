#include<iostream>
#include<map>
using namespace std;
int main() 
{
    map<int, string> m;

    m[1] = "vidya";
    m[2] = "charu";
    m[4] = "khushi";
    m[3] = "dhanu";

    m.insert({5, "specia"});

    cout << "before erase: " << endl;
    for(auto i:m)
    // cout << i.first << " " << i.second << endl;

    // cout << "finding -5" << m.find(-5)<<endl;

    cout << "after erase: " << endl;

    auto it = m.find(3);
    for (auto i = it; i != m.end();i++)
        cout << (*i).first << endl;
}
