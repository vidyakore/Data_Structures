#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;

    cout <<"capacity is: "<< v.capacity() << endl;
    cout <<"size is: "<< v.size() << endl;

    v.push_back(1);

    v.push_back(2);

    cout << "capacity is: "<<v.capacity() << endl;
    cout << "size is: "<< v.size() << endl;

    v.push_back(3);

    vector<int> last(v);   //copies data of v to 'last' vector
    // v.push_back(4);
    cout << "vector ";
    for (int i = 0; i < last.size();i++)
        cout << last[i] << endl;

    cout <<"capacity is: "<< v.capacity() << endl;
    cout << "size is: "<< v.size() << endl;
    v.pop_back();

    cout <<"capacity is: "<< v.capacity() << endl;
    cout << "size is: "<< v.size() << endl;

    cout << "element at 2nd pos is: " << v.at(1)<<endl;

    cout << "all vector elements: ";
    for (int i = 0; i < v.size();i++)
        cout << v[i] << endl;

    cout << "different for loop:" << endl;
    for(int i:v)
        cout << v[i] << endl;

    vector<int> v1;
    int n;
    int b;
    cout << "enter n: ";
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> b;
        v1.push_back(b);
    }

    for (int i = 0; i < n;i++)
    {
        cout << v1[i] << endl;
    }

    

        cout << "using begin end func :" << endl;
        for (auto i = v.begin(); i < v.end();i++)
            cout << *i << endl;
    }