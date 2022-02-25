#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isAscending(int arr[],int index,int size)
{
    if(index == size-1)
    {
        return true;
    }
    
    return arr[index] <= arr[index+1] && isAscending(arr,index+1,size);
}
int main()
{
    int arr[] = {1,3,5,77,100,100};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"outuput is:"<<isAscending(arr,0,size);
    
    return 0;
}
