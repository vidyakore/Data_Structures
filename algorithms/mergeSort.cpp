#include <iostream>
using namespace std;

void merge(int *a,int l,int m,int r)
{
    int i,j,k,nl,nr;
    
    nl = m-l+1;
    nr = r-m;
    int larr[nl], rarr[nr];
    
    for(i=0;i<nl;i++)
        larr[i]=a[l+i];
    for(j=0;j<nr;j++)
        rarr[j] = a[m+1+j];
    i=0;j=0;k=l;
    
    while(i<nl && j<nr)
    {
        if(larr[i]<=rarr[j])
        {
            a[k]=larr[i];
            i++;
        }
        else{
            a[k]=rarr[j];
            j++;
        }
        k++;
    }
    
    while(i<nl)
    {
        a[k]=larr[i];
        i++;k++;
    }
    while(j<nr)
    {
        a[k] = rarr[j];
        j++;k++;
    }
    
}
void mergeSort(int *a,int l,int r)
{
    
    if(l<r)
    {
        int mid=l+(r-l)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int main()
{
    int n;
    cout<<"enter no of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<endl;
    
    cout<<"Array before sorting: ";
    display(a,n);
    
    mergeSort(a,0,n-1);
    cout<<"Array after sorting: ";
    display(a,n);
    return 0;
#include <iostream>
using namespace std;

void merge(int *a,int l,int m,int r)
{
    int i,j,k,nl,nr;
    
    nl = m-l+1;
    nr = r-m;
    int larr[nl],rarr[nr];
    
    for(i=0;i<nl;i++)
        larr[i]=a[l+i];
    for(j=0;j<nr;j++)
        rarr[j] = a[m+1+j];
    i=0;j=0;k=l;
    
    while(i<nl && j<nr)
    {
        if(larr[i]<=rarr[j])
        {
            a[k]=larr[i];
            i++;
        }
        else{
            a[k]=rarr[j];
            j++;
        }
        k++;
    }
    
    while(i<nl)
    {
        a[k]=larr[i];
        i++;k++;
    }
    while(j<nr)
    {
        a[k] = rarr[j];
        j++;k++;
    }
    
}
void mergeSort(int *a,int l,int r)
{
    
    if(l<r)
    {
        int mid=l+(r-l)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int main()
{
    int n;
    cout<<"enter no of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<endl;
    
    cout<<"Array before sorting: ";
    display(a,n);
    
    mergeSort(a,0,n-1);
    cout<<"Array after sorting: ";
    display(a,n);
    return 0;
}