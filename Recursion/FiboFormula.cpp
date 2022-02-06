#include <iostream>
#include <cmath>
using namespace std;

long fiboFormula(int n)
{
    //Best formula to find out the nth fibbonacci number
    
    return round((pow((1+sqrt(5))/2,n)) / sqrt(5));
}

int main()
{
    // for(int i=0;i<10;i++)
    // {
    //     cout<<fiboFormula(i)<<endl;
    // }
    
    cout<<fiboFormula(50);
    return 0;
}