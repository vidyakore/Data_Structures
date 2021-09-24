#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;
vector<vector<int>> adjlist;

void DFS(int i)
{
    visited[i]= 1;
    cout<<i<<" ";
    
    for(auto it=adjlist[i].begin();it!=adjlist[i].end();++it)
    {
        if(!visited[*it])
            DFS(*it);
    }
}

int main()
{
    int NoVertices,NoEdges,start;
    cout<<"Enter No of Vertices: ";
    cin>>NoVertices;
    cout<<"Enter No of Edges: ";
    cin>>NoEdges;
    cout<<"vertices and edges are: "<<NoVertices<<" "<<NoEdges;
    visited.assign(NoVertices,0);
    adjlist.assign(NoVertices,vector<int>());   //adding this removed the bug before it was not taking input edges completely
    int u,v;
    for(int i=0;i<NoEdges;++i)
    {
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    
    cout<<"Enter a vertex no to start: ";
    cin>>start;
    cout<<"DFS is: ";
    DFS(start);
    return 0;
}