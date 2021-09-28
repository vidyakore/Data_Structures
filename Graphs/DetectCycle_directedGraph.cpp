#include <iostream>
#include <vector>
using namespace std;

bool isCyclic_util(vector<int> adj[],vector<bool> visited,int cur)
{
    if(visited[cur])
        return true;
    
    visited[cur] = true;
    bool flag = false;
    for(int i=0;i<adj[cur].size();i++)
    {
        flag = isCyclic_util(adj,visited,adj[cur][i]);
        if(flag)
            return true;
    }
    
    return false;
}
bool isCyclic(int NoVertices, vector<int> adj[])
{
    vector<bool> visited(NoVertices,false);
    bool flag = false;
    
    for(int i=0;i<NoVertices;i++)
    {
        visited[i] = true;
        for(int j=0;j<adj[i].size();j++)
        {
            flag = isCyclic_util(adj,visited,adj[i][j]); 
                if(flag)
                    return true;
        }
        
        visited[i] = false;
    }
    
    return false;
}
int main()
{
    int NoVertices,NoEdges;
    cout << "Enter the no of vertices and edges: ";
    cin>>NoVertices>>NoEdges;
    vector<int> adj[NoVertices];
    int u,v;
    cout << "Enter the edges\n";
    for(int i=0;i<NoEdges;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }

    if(isCyclic(NoVertices,adj))
        cout<<"There is cycle";
    else 
        cout<<"There is a no cycle";
    return 0;
}
