#include<iostream>
#include<vector>
#include<queue>
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

void BFS(vector<int> adj[],int v,int source)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
        visited[i] = false;
    queue<int> q;
    visited[source] = true;
    q.push(source);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int i=0;i<adj[u].size();i++)
        {
            int x = adj[u][i];
            if(visited[x]==false)
            {
                q.push(adj[u][i]);
                visited[x]=true;
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

    cout<<"BFS traversal of the graph is represented by\n";
    BFS(adj,vertices,0 /*source vertex*/);

}
