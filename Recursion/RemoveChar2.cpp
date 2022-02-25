//Not passing ans arugument to CheckA function.

#include <iostream>
#include <string>
using namespace std;

string CheckA(string str)
{
    
    if(str.empty())
    {
        return str;
    }
        
    else
    {
        char ch = str.at(0);
        // cout<<"ch "<<ch<<endl;
        if(ch=='a')
        {
            
            return CheckA(str.substr(1));
        }
        
        else 
        {
            return ch + CheckA(str.substr(1));
        }
    }
    
}

int main()
{
    string str = "abbcdsafdr";
    cout<<CheckA(str);

    return 0;
}
