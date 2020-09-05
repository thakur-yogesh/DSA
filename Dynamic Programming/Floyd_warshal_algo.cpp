#include<iostream>
#include<bits/stdc++.h>
#define INF 10000
using namespace std;

void floyd_warshal(int graph[4][4])
{
    int path[4][4];

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            path[i][j] = graph[i][j];

    //trying all possible shortest paths
    for(int k=0;k<4;k++) //fixing each node one by one
        for(int i=0;i<4;i++) //setting the start node
            for(int j=0;j<4;j++)  // setting up the end node
    {
        if(path[i][k] == INF || path[k][j] == INF)
            continue;
        else if(path[i][j] > path[i][k] + path[k][j])
            path[i][j] = path[i][k] + path[k][j];
    }

    cout<<"After applying the algorithm here is the shortest path matrix\n";

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<path[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    system("COLOR 0A");
    int graph[4][4] = {{0,11,1,6},
                       {11,0,7,3},
                       {1,7,0,2},
                       {6,3,2,0}};
    cout<<"demo graph\n";

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

   floyd_warshal(graph);
}
