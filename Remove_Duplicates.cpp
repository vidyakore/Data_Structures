#include<iostream>
using namespace std;
int removeDuplicates(int *a,int n)
{
    int j=0;
    
    if(n == 0 || n == 1)
        return n;
    
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])
            a[j++] = a[i];
        
    }
    
    a[j++] = a[n-1];
    return j;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n;i++)
        cin >> a[i];
    int l = removeDuplicates(a,n);
    cout<<"l = "<<l<<endl;
    for (int i = 0; i < l;i++)
        cout << a[i]<<" ";
    
    return 0;
}