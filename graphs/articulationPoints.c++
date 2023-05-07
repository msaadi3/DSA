#include <bits/stdc++.h>
using namespace std;

// Find articulation points using Tarjan’s Algorithm.
// T.C && S.C is linear
void dfs(int node, int parent, int &timer,
         unordered_map<int, list<int>> &adjList, vector<int> &low, vector<int> &disc, vector<bool> &visited, vector<int> &ap)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adjList[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        else if (!visited[nbr])
        {
            dfs(nbr, node, timer, adjList, low, disc, visited, ap);

            // update low[node] while returning from this function call
            low[node] = min(low[node], low[nbr]);
            // check if the node is articulation point or not
            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {
            // node is already visited and is not parent that means that edge
            // is back edge so we have to update its low
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // Root case
    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}
int main()
{
    int n = 5;
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // Create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> low(n, -1);
    vector<int> disc(n, -1);
    vector<bool> visited(n, false);
    vector<int> ap(n, 0);
    int timer = 0;

    // DFS
    for (int i = 0; i < edges.size(); i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, timer, adjList, low, disc, visited, ap);
        }
    }

    // print articulation points
    cout << "Articulation points are : ";
    for (int i = 0; i < ap.size(); i++)
    {
        if (ap[i] != 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}