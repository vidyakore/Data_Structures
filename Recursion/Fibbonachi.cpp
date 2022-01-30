#include <iostream>

using namespace std;
int fib(int n)
{
    if(n<2)
    {
        return n;
    }
    else{
        return fib(n-1)+fib(n-2); 
    }
    
}
int main()
{
    int n;
    cout<<"enter a number to find fibbonachi: ";
    cin>>n;
    
    cout<<fib(n);

    return 0;
}
