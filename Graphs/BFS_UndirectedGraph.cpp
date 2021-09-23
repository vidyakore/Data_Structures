#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// code is working for graph having starting vertex 0

vector<int> visitedList;
vector<vector<int>> adjList;

void BFS(int ele)
{
    std::queue<int> q;
    q.push(ele);
    visitedList[ele]=1;
    cout << "BFS is: ";
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        cout<<node<<" ";
        
        
        for(auto it= adjList[node].begin();it!=adjList[node].end();it++)
        {
            if(!visitedList[*it])
            {
                q.push(*it);
                visitedList[*it]=1;
                
            }
        }
    }
            
    
}
int main()
{
    int NoVertices,NoEdges;
    cout<<"Enter the no of vertices: ";
    cin>>NoVertices;
    visitedList.assign(NoVertices,0);
    adjList.assign(NoVertices,vector<int>());
    cout<<"Enter the no of edges: ";
    cin>>NoEdges;
    cout<<"vertices and edges are: "<<NoVertices<<" "<<NoEdges;
    
    int u,v;
    
    for(int i=0;i<NoEdges;++i)
    {
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);    //if graph is undirected omit this line
    }
    
    
    for(int i=0;i<NoVertices;i++)
    {
        if(!visitedList[i])
            BFS(i);
    }
    return 0;
}