#include<iostream>
using namespace std;
#include<vector>

int removeElement(vector <int>&a,int val)
{
    int j = 0;
    for (int i = 0; i < a.size();i++)
    {
        if(a[i]!=val)
            a[j++] = a[i];
    }

    return j;
}
int main()
{
    vector<int> arr;
    int n;
    cout << "enter n: ";
    cin>>n;
    int num,val;
    for (int i = 0; i < n;i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    cout << "Enter a value: ";
    cin>>val;
    int l = removeElement(arr, val);
    for (int i = 0; i < l;i++)
        cout << arr[i]<<" ";
}