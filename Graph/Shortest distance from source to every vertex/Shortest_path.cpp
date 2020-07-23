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

void shortestPath(vector<int> adj[],int V,int source)
{
    int distances[V+1];
    for(int i=0;i<V;i++)
        distances[i] = 0;

    distances[source] = 0;

    bool visited[V+1];
    for(int i=0;i<V;i++)
        visited[i] = false;
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][v];
            if(visited[v]==false)
            {
                distances[v] = distances[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for(int i=0;i<V;i++)
    {
        cout<<"the distance of the vertex "<<i<<" from the source vertex is -> "<<distances[i]<<endl;
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

    cout<<"shortest distance for every vertex from the source is given by\n";
    shortestPath(adj,vertices,0);


}
