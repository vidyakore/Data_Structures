#include<bits/stdc++.h>
using namespace std;

#define NoVertices 4

void FloydWarshall(int graph[NoVertices][NoVertices])
{
    //creating array to store short path for each vertex
    int shortDistance[NoVertices][NoVertices];
    
    
    //copy graph into shortDistance array
    for(int i=0;i<NoVertices;i++)
    {
        for(int j=0;j<NoVertices;j++)
            shortDistance[i][j] = graph[i][j];
    }
    
    //find the shortest Distance for each vertex
    
    for(int k=0;k<NoVertices;k++)
    {
        for(int i=0;i<NoVertices;i++)
        {
            for(int j=0;j<NoVertices;j++)
            {
                if(shortDistance[i][k]==INT_MAX || shortDistance[k][j]==INT_MAX)
                    continue;
                else if(shortDistance[i][k] + shortDistance[k][j] < shortDistance[i][j])
                {
                    shortDistance[i][j] = shortDistance[i][k] + shortDistance[k][j];
                }
            }
        }
    }
    
    //check if negative edge weight cycle contains by checking if self loop value is less than 0
    
    for(int i=0;i<NoVertices;i++)
    {
        if(shortDistance[i][i]<0)
        {
            cout<<"negative edge weight cycle is detected\n";
            return;
        }
            
    }
    
    //print the shortest Distance for each vertices pair
    cout<<"vertex1 "<<"vertex2 "<<"shortest path value"<<endl;
    for(int i=0;i<NoVertices;i++)
    {
        for(int j=0;j<NoVertices;j++)
        {
            cout<<i<<"\t"<<j<<"\t"<<shortDistance[i][j]<<endl;
        }
    }
    
    
}

int main()
{
    int NoEdges;
    // cout<<"Enter Number of vertices: ";
    // cin>>NoVertices;
    cout<<"Enter Number of Edges: ";
    cin>>NoEdges;
    
    //take graph as input
    
    int graph[NoVertices][NoVertices] = { {0,INT_MAX,INT_MAX,INT_MAX},
                                            {INT_MAX,0,INT_MAX,INT_MAX},
                                            {INT_MAX,INT_MAX,0,INT_MAX},
                                            {INT_MAX,INT_MAX,INT_MAX,0}};
    
    cout<<"\nintially graph is: \n";
    for(int i=0;i<NoVertices;i++)
    {
        for(int j=0;j<NoVertices;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // int graph[4][4] = { {0,3,INT_MAX,5},
    //                                       {2, 0, INT_MAX, 8},
    //                                       {INT_MAX, 1, 0, INT_MAX},
    //                                       {INT_MAX, INT_MAX, 2, 0} };
    
    cout<<"enter edges with weights:\n";
    int v1,v2,wt;
    for(int i=0;i<NoEdges;i++)
    {
        cin>>v1>>v2>>wt;
        graph[v1][v2] = wt;
    }
    
    cout<<"\nafter giving input graph is as follows: \n";
    for(int i=0;i<NoVertices;i++)
    {
        for(int j=0;j<NoVertices;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    FloydWarshall(graph);
    
    

    return 0;
}


//TIME COMPLEXITY = O(V^3)
