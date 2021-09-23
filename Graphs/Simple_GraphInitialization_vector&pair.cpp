#include <iostream>
#include <vector>
using namespace std;

void display_Graph(std::vector <int> &v,std::vector <std::pair <int,int>> &e)
{
    cout<<"vertices are: ";
    for(auto i: v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    for(auto i: e)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
int main()
{
    int numberOfEdges,numberOfVertices;
    vector <int> v;
    vector <pair <int,int>> e;
    cout<<"Enter no of vertices: ";
    cin>>numberOfVertices;
    cout<<"enter vertices:\n";
    for(int i=0;i<numberOfVertices;i++)
    {
        int ele_V;
        cin>>ele_V;
        v.push_back(ele_V);
    }
        
    cout<<"Enter No of Edges: ";
    cin>>numberOfEdges;
    cout<<"enter edges:\n";
    for(int i=0;i<numberOfEdges;i++)
    {
        int e1,e2;
        cin>>e1>>e2;
        e[i].first = e1;
        e[i].second = e2;
    }
    
    // display_Graph(v,e);

    cout<<"vertices are: ";
    for(auto i: v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    for(auto i: e)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}
