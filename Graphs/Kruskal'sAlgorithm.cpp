//Kruskal's algorithm for finding minimum spanning tree
//TIME COMPLEXITY - O(ElogE + ElogV)

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int parent,rank;
};

struct Edge
{
    int src,dest,wt;
};

vector<node> parentSet;
vector<Edge> mst;

int find(int v)
{
    if(parentSet[v].parent == -1)
        return v;
    return parentSet[v].parent = find(parentSet[v].parent);
}

void union_set(int fromP,int toP)
{
    if(parentSet[fromP].rank > parentSet[toP].rank)
        parentSet[toP].parent = fromP;
    else if(parentSet[fromP].rank < parentSet[toP].rank)
        parentSet[fromP].parent = toP;
    else
    {
        parentSet[fromP].parent = toP;
        parentSet[toP].rank += 1;
    }
}

bool comparator(Edge a,Edge b)
{
    return a.wt < b.wt;
}

void printEdgeList(vector<Edge>& Graph)
{
	for(auto p: Graph)
		cout<<"src: "<<p.src<<"  dst: "<<p.dest<<"  wt: "<<p.wt<<"\n";
	cout<<"============================================================\n";
}

void printMST(vector<Edge> &mst)
{
    cout<<"MST is: "<<endl;
    for(auto p : mst)
    {
        cout<<"src: "<<p.src<<" des: "<<p.dest<<" weight: "<<p.wt<<endl;
    }
    
}
void Kruskal(vector<Edge> Graph,int NoV,int NoE)
{
    cout<<"print graph before sorting: \n";
    printEdgeList(Graph);
    sort(Graph.begin(),Graph.end(),comparator);
    cout<<"after sorting graph is: "<<endl;
    printEdgeList(Graph);
    
    
    int i=0,j=0;
    while(i<NoV-1 && j<NoE)
    {
        int fromP = find(Graph[j].src);
        int toP = find(Graph[j].dest);
        
        if(fromP == toP)
        {
            ++j;
            cout<<"found a loop between "<<fromP<<" and "<<toP<<endl;
            continue;
        }
        
        union_set(fromP,toP);
        mst.push_back(Graph[j]);
        ++i;
    }
}
int main()
{
    int NoV,NoE;
    cout<<"Enter the no of vertices and edges: \n";
    cin>>NoV>>NoE;
    
    parentSet.resize(NoV);
    
    for(int i=0;i<NoV;i++)
    {
        parentSet[i].parent = -1;
        parentSet[i].rank = 0;
    }
    
    vector<Edge> Graph;
    Edge temp;
    for(int i=0;i<NoE;i++)
    {
        int from,to,wt;
        cin>>from>>to>>wt;
        temp.src = from;
        temp.dest = to;
        temp.wt = wt;
        Graph.push_back(temp);
    }
    
    Kruskal(Graph,NoV,NoE);
    
    printMST(mst);
    
    
    
    return 0;
}