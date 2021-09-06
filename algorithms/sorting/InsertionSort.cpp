#include <iostream>

using namespace std;

void swap(int *array,int a,int b)
{
    int temp=array[a];
    array[a]=array[b];
    array[b]=temp;
}

void InsertionSort(int *array,int size)
{
    for(int pos=1;pos<size;pos++)
    {
        int nextPos = pos;
        while(nextPos>0 && array[nextPos]<array[nextPos-1])
        {
            swap(array,nextPos,nextPos-1);
            nextPos--;
        }
    }
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
    
    InsertionSort(array,size);
    cout<<"Array after sorting: ";
    display(array,size);
    

    return 0;
}
