#include <iostream>

using namespace std;

void swap(int *array,int a,int b)
{
    int temp=array[a];
    array[a]=array[b];
    array[b]=temp;
}

void Insert(int *array,int start)
{
    int pos = start;
    while(pos>0 && array[pos]<array[pos-1])
    {
        swap(array,pos,pos-1);
        pos--;
    }
}

void InsertionSort(int *array,int start,int size)
{
    if (start>=size-1)
        return;
    
    Insert(array,start);
    InsertionSort(array,start+1,size);
    return;

}

void display(int array[],int size)
{
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int array[size];
    
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }
        
    cout<<"Array before sorting: ";
    display(array,size);
    
    InsertionSort(array,0,size);
    cout<<"Array after sorting: ";
    display(array,size);
    

    return 0;
}
