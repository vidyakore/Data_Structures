#include <iostream>
#include <string>
using namespace std;

int CheckA(string ans,string str,int i,int l)
{
    
    if(i==l-1)
    {
        cout<<ans<<endl;
        return 0;
    }
        
    else
    {
        if(str[i]!='a')
        {
            ans+=str[i];
            // cout<<"a is not there "<<ans<<endl;
            CheckA(ans,str,i+=1,l);
        }
        
        else if(str[i]=='a')
        {
            CheckA(ans,str,i+=1,l);
        }
    }
    
    return 0;
}

int main()
{
    string str = "Hiavidya";
    string ans;
    int l = str.length();
    CheckA(ans,str,0,l);
    // cout<<l;
    return 0;
}
