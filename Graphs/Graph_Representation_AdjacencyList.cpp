// #include <iostream>
// #include <map>
// #include <set>
// using namespace std;

// class Graph
// {
//     public:
//         Graph(map<int, std::set<int>> &vertices) : v_(vertices) {}
//         map<int, set<int>> v_;
        
// };
// int main()
// {
//     map<int, set<int>> vertices{
//         {0,{1,2}},
//         {1,{0,2,3,4}},
//         {2,{0,1,3}},
//         {3,{1,2,4}}
//     };
    
//     Graph g(vertices);
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// code is working for graph having starting vertex 0

vector<int> visitedList;
vector<vector<int>> adjList;

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
    
    
    // for(auto i : adjList)
    // {
    //     cout<<i<<endl;
    //     // for(int j=i;j<adjList[i].size();j++)
    //     // {
    //     //     cout<<"a[i][j] = "<<adjList[i]<<endl;
    //     // }
    // }
    
    for(int node=0;node<NoVertices;node++)
    {
        cout<<"\n"<<node<<"->";
        for(auto it= adjList[node].begin();it!=adjList[node].end();it++)
        {
            cout<<*it<<" ";
        }   
    }
    

    return 0;
}
