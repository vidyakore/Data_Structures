//Disjoint set UNION by Rank and FIND by Path compression
//TIME COMPLEXITY: O(E.V)

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int parent;
    int rank;
};
vector<node> parentSet;

//find the absolute root for given element or node
int FIND(int ele)
{
    if(parentSet[ele].parent == -1)
        return ele;
    return parentSet[ele].parent = FIND(parentSet[ele].parent);
}

void UNION(int fromP,int toP)
{
    fromP = FIND(fromP);
    toP = FIND(toP);
    
    if(parentSet[fromP].rank > parentSet[toP].rank)
        {
            parentSet[toP].parent = fromP;
        }
    else if(parentSet[fromP].rank < parentSet[toP].rank)
    {
        parentSet[fromP].parent = toP; 
    }
    else
    {
        parentSet[toP].parent = fromP;
        parentSet[fromP].rank += 1;
    }
}
bool isCyclic(vector<pair<int,int>> Graph)
{
    for(auto i : Graph)
    {
        int fromP = FIND(i.first);
        int toP = FIND(i.second);
        
        if(fromP == toP)
            return true;
        
        //UNION operation by rank
        UNION(fromP,toP);
        
    }
    return false;
}

int main()
{
    int NoV,NoE;
    cout<<"Enter No of Vertices and edges: ";
    cin>>NoV>>NoE;
    
    parentSet.resize(NoV);
    for(int i=0;i<NoV;i++)
    {
        parentSet[i].parent = -1;
        parentSet[i].rank = 0;
    }

    vector<pair<int,int>> Graph;
    
    
    for(int i=0;i<NoE;i++)
    {
        int from,to;
        cin>>from>>to;
        Graph.push_back({from,to});
    }
    
    if(isCyclic(Graph))
    {
        cout<<"Graph is Cyclic\n";
    }
    else
        cout<<"Graph is not cyclic\n";
        
    //print parentSet
    cout<<"Node parent rank"<<endl;
    for(int i=0;i<NoV;i++)
    {
        cout<<i<<" "<<parentSet[i].parent<<" "<<parentSet[i].rank<<endl;
    }
    return 0;
}

