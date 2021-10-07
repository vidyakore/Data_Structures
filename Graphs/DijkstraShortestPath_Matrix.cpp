#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define V 4

int shortesDis(vector<bool> &processed, vector<int> &value)
{
    int minimum = INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(processed[i]==false && value[i]<minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    
    return vertex;
}

void dijkstra(int graph[V][V],int src)
{
    int parent[V];
    vector<bool> processed(V,false);
    vector<int> value(V,INT_MAX);
    
    parent[0] = -1;
    value[0] = 0;
    
    for(int i=0;i<V-1;i++)
    {
        int u = shortesDis(processed,value);
        
        processed[u] = true;
        
        for(int j=0;j<V;j++)
        {
            if(graph[u][j]!=0 && processed[j]==false && value[u]!=INT_MAX && 
            (value[u]+graph[u][j] < value[j]))
            {
                value[j] = value[u]+graph[u][j];
                parent[j] = u;
            }
            
        }
    }
    
    for(int i=0;i<V;i++)
    {
        cout<<"u->v: "<<parent[i]<<"->"<<i<<" wt= "<<graph[parent[i]][i]<<" distance is: "<<value[i]<<endl;
    }
}
int main()
{
    // int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //                     { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //                     { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //                     { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //                     { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //                     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //                     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //                     { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
                        
    int graph[V][V] = { {0,1,3,0},
                        {0,0,2,5},
                        {0,0,0,4},
                        {0,0,0,0} };
                        
    dijkstra(graph,0);

    return 0;
}
