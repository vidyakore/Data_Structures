#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> adj;
vector<int> visited;
bool isCycle_Util(vector<vector<int>> adj,int cur,vector<int> visited)
{
    if(visited[cur])
        return true;
    
    visited[cur] = 1;
    bool flag = false;
    for(int i=0;i<adj[cur].size();i++)
    {
        flag = isCycle_Util(adj,adj[cur][i],visited);
        if(flag)
            return true;
    }
    
    return false;
}
bool isCycle(vector<vector<int>> adj, vector<int> visited,int NoVertices)
{
    bool flag = false;
    for(int i=0;i<NoVertices;i++)
    {
        visited[i] = 1;
        for(int j=0;j<adj[i].size();j++)
        {
            flag = isCycle_Util(adj,adj[i][j],visited);
            if(flag)
                return true;   
        }
        
        visited[i] = false;    
    }
    
    return false;
}

void topologicalSortDFS(vector<vector<int>>&adj, vector<int> &visited,int v,stack<int> &mystack)
{
    // cout<<"in topodfs v = "<<v<<endl;
    visited[v] = 1;
    for(int i=0;i<adj[v].size();i++)
    {
        if(!visited[adj[v][i]])
        {
            topologicalSortDFS(adj,visited,adj[v][i],mystack);
        }
            
    }
    cout<<"v is: "<<v<<endl;
    mystack.push(v);
}

int main()
{
    int NoVertices,NoEdges;
    stack<int> mystack;
    cout<<"Enter No of Vertices: ";
    cin>>NoVertices;
    cout<<"Enter No of Edges: ";
    cin>>NoEdges;
    cout<<"vertices and edges are: "<<NoVertices<<" "<<NoEdges;
    visited.assign(NoVertices,0);
    adj.assign(NoVertices,vector<int>());   //adding this removed the bug before it was not taking input edges completely
    int u,v;
    for(int i=0;i<NoEdges;++i)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    
    if(isCycle(adj,visited,NoVertices))
        cout<<"can't perform topological sort because graph has cycle";
    else
    {
        for(int i=0;i<NoVertices;i++)
        {
            if(!visited[i])
            {
                // cout<<"in main for "<<i<<endl;
                topologicalSortDFS(adj,visited,i,mystack);
                
            }
                
        }
    
        while(!mystack.empty())
        {
            cout<<mystack.top()<<" ";
            mystack.pop();
        }
    }
    
    

    return 0;
}