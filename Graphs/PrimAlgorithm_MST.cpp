#include <bits/stdc++.h>
using namespace std;

#define V 6

int FindMinVertex(vector<int> value, vector<bool> MSTset)
{
    int minimum = INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(MSTset[i]==false && value[i]<minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    
    return vertex;
}

void Prim(int graph[V][V])
{
    int parent[V];
    vector<int> value(V,INT_MAX);
    vector<bool> MSTset(V,false);
    
    value[0] = 0;
    parent[0] = -1;
    
    for(int i=0;i<V-1;i++)
    {
        int U = FindMinVertex(value,MSTset);
        MSTset[U] = true;
        
        for(int j=0;j<V;j++)
        {
            if(graph[U][j] != 0 && MSTset[j] == false && graph[U][j] < value[j])
            {
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }
    
    //print MST
    cout<<"Source\t "<<"destination "<<"\tvalue"<<endl;
    for(int i=1;i<V;i++)
    {
        cout<<parent[i]<<"\t\t"<<i<<"\t"<<value[i]<<endl;
    }
    
}

int main()
{
    int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };
						
	Prim(graph);

    return 0;
}


//TIME COMPLEXITY = O(V^2)