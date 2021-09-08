#include <iostream>
using namespace std;

void swap(int *array,int startPosition, int minPosition)
{
    int temp = array[startPosition];
    array[startPosition] = array[minPosition];
    array[minPosition] = temp;
}

void SelectionSort(int *array,int startPosition,int size)
{
    if(startPosition >= size-1)
        return;
        
    int minPosition = startPosition;
    for(int i=startPosition+1;i<size;i++)
    {
        if(array[i]<array[minPosition])
            minPosition=i;
    }
    
    swap(array,startPosition,minPosition);
    SelectionSort(array,startPosition+1,size);
    
    
}

void display(int array[],int size)
{
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
        cin>>array[i];
    
    cout<<"Array before sorting: ";
    display(array,n);
    SelectionSort(array,0,n);
    cout<<"Array after sorting: ";
    display(array,n);

    return 0;
}