//Disjoint sets and FIND and UNION operations
//Time Complexity = O(E*V)


#include <bits/stdc++.h>
using namespace std;
vector<int> parent;

int find(int node)
{
    if(parent[node] == -1)
        return node;
    return find(parent[node]);
}

void union_set(int fromp,int top)
{
    fromp = find(fromp);
    top = find(top);
    parent[fromp] = top;
}

bool isCycle(vector<pair<int,int>> &set)
{
    for(auto i : set)
    {
        int fromp = find(i.first);       //find absolute parent of i
        int top = find(i.second);
        
        if(fromp == top)
        {
            cout<<"fromp and top = "<<fromp<<" "<<top<<endl;
                return true;
                
        }
            
        
        //union of sets
        
        union_set(fromp,top);
    }
    
    return false;
    
}

void final_union(int V)
{
    int s1_root = 0,s2_root = 0;
    for(int i=0;i<V;i++)
    {
        if(parent[i] == -1)
        {
            if(s1_root == 0)
            {
                s1_root = i;
            }
            else
            {
                s2_root = i;
            }
        }
    }
    
    //combine/ merge the sets
    
    parent[s2_root] = s1_root;
    
}
int main()
{
    int V,E;
    cout<<"Enter No of vertices and Edges: ";
    cin>>V>>E;
    
    vector<pair<int,int>> set;
    parent.resize(V,-1);
    int from,to;
    
    for(int i=0;i<E;i++)
    {
        cin>>from>>to;
        set.push_back({from,to});
    }
    

    if(isCycle(set))
        cout<<"There is a cycle"<<endl;
    else
        cout<<"There is a no cycle"<<endl;
    
    final_union(V);
    //print the merged array
    cout<<"merged array is: "<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<parent[i]<<" -> "<<i<<endl;
    }
    
    return 0;
}