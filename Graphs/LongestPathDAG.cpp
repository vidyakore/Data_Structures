#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// typedef push_back pb;
// #define pb push_back;

void DFS(int n,vector<vector<int>> adjList, vector<bool> visited,vector<int> &dp)
{
    visited[n] = true;
    
    for(int i=0;i<adjList[n].size();i++)
    {
        if(!visited[adjList[n][i]])
            DFS(adjList[n][i],adjList,visited,dp);
            
        dp[n] = max(dp[n],1+dp[adjList[n][i]]);
    }
}

int longestPathDAG(vector<vector<int>> adjList,int NoVertices)
{
    vector<int> dp(NoVertices,0);
    vector<bool> visited(NoVertices,false);
    
    for(int i=0;i<NoVertices;i++)
    {
        if(!visited[i])
            DFS(i,adjList,visited,dp);
    }
    
    int ans=0;
    cout<<"printing dp: ";
    for(int i=0;i<NoVertices;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<NoVertices;i++)
    {
        ans = max(dp[i],ans);
    }
    
    return ans;
}
int main()
{
    // adjList.assign()
    int NoVertices,NoEdges;
    cout<<"Enter the No of Vertices: ";
    cin>>NoVertices;
    cout<<"Enter the number of Edges: ";
    cin>>NoEdges;
    vector<vector<int>> adjList(NoVertices);
    
    int u,v;
    for(int i=0;i<NoEdges;i++)
    {
        cin>>u>>v;
        adjList[u].push_back(v);
    }
    
    cout<<longestPathDAG(adjList,NoVertices);
    
    return 0;
}
