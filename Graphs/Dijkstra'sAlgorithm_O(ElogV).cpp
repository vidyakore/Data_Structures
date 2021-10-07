//Time complexity is O(ElogV)


#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int,int> ipair;

void addEdge(vector<pair<int,int>> adjList[],int v1,int v2,int w)
{
    adjList[v1].push_back(make_pair(v2,w));
}

void DijkstraShortestPath(vector<pair<int,int>> adjList[],int src,int NoVertices)
{
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    vector<int> distance(NoVertices,INT_MAX);
    
    distance[src] = 0;
    pq.push(make_pair(src,0));
    
    while(!pq.empty())
    {
        int v1 = pq.top().first;
        
        pq.pop();
        
        for(auto x : adjList[v1])
        {
            int v2 = x.first;
            int weight = x.second;
            
            if(distance[v1]+weight < distance[v2])
            {
                distance[v2] = distance[v1]+weight;
                pq.push(make_pair(v2,distance[v2]));
            }
        }
    }
    
    cout<<"Vetex distance from source"<<endl;
    for(int i=0;i<NoVertices;i++)
    {
        cout<<i<<"\t"<<distance[i]<<endl;
    }
    
}
int main()
{
    int NoVertices,NoEdges;
    cout<<"enter no of vertces: ";
    cin>>NoVertices;
    cout<<"Enter no of Edges: ";
    cin>>NoEdges;
    
    vector<ipair>adjList[NoVertices];
    
    int v1,v2,w;
    
    for(int i=0;i<NoEdges;i++)
    {
        cin>>v1>>v2>>w;
        addEdge(adjList,v1,v2,w);
    }
    int src;
    cout<<"Enter source vertex: ";
    cin>>src;
    
    DijkstraShortestPath(adjList,src,NoVertices);
    
    
    return 0;
}
