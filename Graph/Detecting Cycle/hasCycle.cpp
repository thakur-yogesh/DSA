#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i;
        for(int j=0;j<adj[i].size();j++)
        {
           int x;
           x=adj[i][j];
           cout<<"->"<<x;
        }
        cout<<endl;
    }
}

bool checkCycle(vector<int> adj[],int source,bool visited[],int parent)
{
    visited[source] = true;

    for(int u=0;u<adj[source].size();u++)
    {
        int x = adj[source][u];
        if(visited[x]==false)
        {
            if(checkCycle(adj,x,visited,source)==true)
                return true;
        }
        else if(x!=parent)
            return true;
    }
    return false;
}

bool hasCycle(vector<int> adj[],int V,int source)
{
    bool visited[V+1];
    for(int i=0;i<V;i++)
        visited[i] = false;

    for(int v=0;v<V;v++)
    {
        if(visited[v]==false)
        {
            if(checkCycle(adj,v,visited,-1)==true)
               return true;
        }
    }
    return false;

}

int main()
{
    cout<<"enter the number of the vertices and edges\n";
    int vertices,edges;
    cin>>vertices>>edges;
    vector<int> adj[vertices];
    while(edges--){
        cout<<"enter the two vertices that represent an edge from vertex u to v\n";
        int u,v;
        cin>>u>>v;
        if(u>vertices||v>vertices){
            cout<<"soryyyy!! you just entered a wrong vertex\n";
            break;
        }
        addEdge(adj,u,v);
    }

    bool cycle;

    cycle = hasCycle(adj,vertices,0);

    (cycle)? cout<<"the graph has cycle\n" : cout<<"no sir, no cycles in the graph\n";



}
