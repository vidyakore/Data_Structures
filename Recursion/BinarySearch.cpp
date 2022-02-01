#include <iostream>
using namespace std;

int search(int arr[],int key,int start,int end)
{
    if(start>end)
        return -1;
        
    int mid = (start+end)/2;
    
    if(arr[mid]==key)
        return mid;
    if(key<arr[mid])
        return search(arr,key,start,mid-1);
    else
        return search(arr,key,mid+1,end);
}
int main()
{
    int arr[5] = {1,3,5,8,9};
    int key = 9;
    int start=0;
    int l = sizeof(arr)/sizeof(arr[0]);
    cout<<search(arr,key,start,l-1);
    return 0;
}
