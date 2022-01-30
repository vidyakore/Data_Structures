#include<iostream>
#include<array>
using namespace std;
int  main()
{
    array<int, 5> a = {1, 2, 3, 4, 50};
    int size = a.size();
    cout << "size of a: " << a.size()<<endl;
    for (int i = 0; i < size;i++)
        cout << a[i] << endl;

    cout << "element at 3rd position is: " << a.at(2)<<endl;

    cout << "check array is empty or not: " << a.empty() << endl;

    cout << "first element is: " << a.front() << endl;
    cout << "last element is: " << a.back() << endl;
}
