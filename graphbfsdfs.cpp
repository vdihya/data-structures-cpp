#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}
void dfs(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            dfs(adj[u][i], adj, visited);
}

void _dfs(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            dfs(u, adj, visited);
}


void bfs(int u, vector<int> adj[], vector<bool> &visited)
{
    queue<int> q;

    q.push(u);
    visited[u] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        // Enqueue all adjacent of f and mark them visited
        cout << f << " ";
        for (int i = 0; i < adj[f].size(); i++)
         {
            if(visited[adj[f][i]] ==false)
            {
                q.push(adj[f][i]);
                visited[adj[f][i]] = true;
            }
        }
    }
}

void _bfs(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for(int u=0;u<V;u++)
        if(visited[u] == false)
            bfs(u,adj,visited);
}

int main()
{ int V = 6;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 2);
    printf("\nDFS:\n");
    _dfs(adj,V);
    printf("\nBFS:\n");
    _bfs(adj,V);
    return 0;

}
