#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);
    v.push_back(8);

    cout << "finding 3 ->" << binary_search(v.begin(), v.end(), 9)<<endl;

    // std::cout << "lower bound->" <<lower_bound(v.begin(), v.end(), 3);
    cout << "upper bound-> " << upper_bound(v.begin(), v.end(), 4) - v.begin() << endl;
    // cout << "lower  bound-> "<< lower_bound(v.begin(), v.end(), 4)<< endl;

    int a = 3;
    int b = 5;
    cout << "max no is: " << max(a, b) << endl;
    cout << "min no is:   " << min(a, b) << endl;

    swap(a, b);
    cout << "a= " << a << " "<< "b= " <<b<< endl;

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    // cout <<"after reversing string: "<< abcd;

    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "after rotate " << endl;
    for(int i:v){
        cout << i << " ";
    }
}