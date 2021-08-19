#include <iostream>
using namespace std;
void  swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int a[],int n)
{
    if(n==1)
        return;
    for (int i = 0; i < n - 1;i++)
    {
        if(a[i]>a[i+1])
            swap(&a[i], &a[i + 1]);
    }
    bubble_sort(a, n - 1);
}

int main()
{
    int a[]={3,2,4,5,2,9,5};
    int n = sizeof(a) / sizeof(a[0]);
    bubble_sort(a, n);
    cout << "sorted array is: " << endl;
    for (int i = 0; i < n;i++)
        cout << a[i]<<" ";

        return 0;
}

