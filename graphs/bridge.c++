#include <bits/stdc++.h>
using namespace std;

// T.C && S.C is linear

void dfs(unordered_map<int, list<int>> &adjList, vector<bool> &visited, int &timer, vector<int> &low, vector<int> &disc,
         vector<vector<int>> &ans, int node, int parent)
{

    visited[node] = true;
    low[node] = disc[node] = timer++;

    for (auto nbr : adjList[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        else if (!visited[nbr])
        {
            dfs(adjList, visited, timer, low, disc, ans, nbr, node);
            // update the low[node] when returning from this call
            low[node] = min(low[node], low[nbr]);
            // check if the edge is bridge
            if (low[nbr] > disc[node])
            {
                // edge is bridge
                vector<int> temp;
                temp.push_back(nbr);
                temp.push_back(node);
                ans.push_back(temp);
            }
        }
        else
        {
            // node is already visited and is not parent that means that edge
            // is back edge so we have to update its low
            low[node] = min(low[node], disc[nbr]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{

    // Create adjacency list first
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(v, false);
    vector<int> low(v, -1);
    vector<int> disc(v, -1);
    vector<vector<int>> ans;
    int parent = -1;
    int timer = 0;

    // DFS
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(adjList, visited, timer, low, disc, ans, i, parent);
        }
    }

    return ans;
}
int main()
{
    return 0;
}