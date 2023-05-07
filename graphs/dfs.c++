#include <bits/stdc++.h>
using namespace std;

// T.S && S.C is linear

void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &component, int node)
{
    component.push_back(node);
    visited[node] = true;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(adjList, visited, component, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            // didn't get it at all about this component(vector) and ans(vector of vector). why we are not directly puhing into ans and why vector of vector instead of single vector
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{
    return 0;
}