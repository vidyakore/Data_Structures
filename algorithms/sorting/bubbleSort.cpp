#include <iostream>
using namespace std;
void  swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void  bubble_sort(int a[],int n)
{
    bool swapped = false;                                                           //efficient method;
    for (int i = 0; i < n - 1;i++)
    {
        for (int j = 0; j < n - i - 1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j], &a[j + 1]);
                swapped = true;
            }
                
        }
        if(swapped == false)                 //if no element is swapped in an inner loop break the loop to reduce time complexity in best case it will be O(n)
            break;
    }
}
int main()
{
    int a[]={3,2,4,5,2,9,5,81,34,11};
    int n = sizeof(a) / sizeof(a[0]);
    bubble_sort(a, n);
    cout << "sorted array is: " << endl;
    for (int i = 0; i < n;i++)
        cout << a[i]<<" ";

        return 0;
}