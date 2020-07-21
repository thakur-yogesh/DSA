#include<iostream>
#include<vector>
#include<stack>
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

void DFSusingStack(vector<int> adj[],int V,int source)
{
    bool visited[V+1];
    for(int i=0;i<V;i++)
        visited[i] = false;
    stack<int> s;
    s.push(source);
    visited[source] = true;
    while(!s.empty())
    {
        int u = s.top();
        s.pop();
        cout<<u<<" ";
        for(int i=0;i<adj[u].size();i++)
        {
            int x;
            x = adj[u][i];
            if(visited[x]==false)
            {
                s.push(adj[u][i]);
                visited[x] = true;
            }
        }
    }
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
    cout<<"here is the adjacency list representation of the graph\n";
    printGraph(adj,vertices);

    cout<<"DFS traversal of the graph is represented by:\n";
    DFSusingStack(adj,vertices,0/*source*/);

}
