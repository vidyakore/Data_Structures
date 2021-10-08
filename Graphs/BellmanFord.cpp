#include<bits/stdc++.h>
using namespace std;

struct edge{
    int src,dest,weight;
};
int V,E;

void bellmanFord(vector<edge> &Edge)
{
    int parent[V];
    int cost_parent[V];     //optional 
    
    vector<int> value(V,INT_MAX);
    
    parent[0] = -1;
    value[0] = 0;
    
    bool updated;
    for(int i=0;i<V-1;++i)
    {
        updated = false;
        
        for(int j=0;j<E;++j)
        {
            int V1 = Edge[j].src;
            int V2 = Edge[j].dest;
            int wt = Edge[j].weight;
            
            if(value[V1]!=INT_MAX && value[V1]+wt < value[V2])
            {
                value[V2] = value[V1]+wt;
                parent[V2] = V1;
                cost_parent[V2] = value[V2];
                updated = true;
            }
        }
        
        if(!updated)
            break;
    }
    
    for(int j=0;j<E && updated==true;++j)
    {
        int V1 = Edge[j].src;
        int V2 = Edge[j].dest;
        int wt = Edge[j].weight;
        
        if(value[V1]!=INT_MAX && value[V1]+wt < value[V2])
        {
            cout<<"Graph has negative edge cycle"<<endl;
            return;
        }
        
        
    }
    
    //print shortest path Graph
    for(int i=1;i<V;i++)
    {
        cout<<"U->V "<<parent[i]<<"->"<<i<<" cost to reach "<<parent[i]<<" from source 0 = "<<value[i]<<endl;
    }
    
    //print onlly distance and vertex
    cout<<"Vertex"<<"distancefrom source"<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<i<<"\t"<<value[i]<<endl;
    }
}

int main()
{
    cout<<"Enter no of vertices and edges: ";
    cin>>V>>E;
    
    vector<edge> Edge(E);
    int source,destination,weight;
    for(int i=0;i<E;i++)
    {
        cin>>source>>destination>>weight;
        
        Edge[i].src = source;
        Edge[i].dest = destination;
        Edge[i].weight = weight;
    }
    
    bellmanFord(Edge);
    
    return 0;
}



//TIME COMPLEXITY = O(VE)