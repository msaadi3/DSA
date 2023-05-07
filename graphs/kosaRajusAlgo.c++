#include <bits/stdc++.h>
using namespace std;

// Kosaraju's algoritham for strongly connected components in directed graph
// T.C && S.C is linear

void dfs(unordered_map<int, list<int>> &adjList, stack<int> &topoSort, vector<bool> &visited, int node)
{
    visited[node] = true;

    for (auto nbr : adjList[node])
    {
        if (!visited[nbr])
        {
            dfs(adjList, topoSort, visited, nbr);
        }
    }
    topoSort.push(node);
}

void dfsForTranspose(unordered_map<int, list<int>> &transpose, vector<bool> &visited, int node)
{

    visited[node] = true;

    for (auto nbr : transpose[node])
    {
        if (!visited[nbr])
        {
            dfsForTranspose(transpose, visited, nbr);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // Topological sort
    stack<int> topoSort;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(adjList, topoSort, visited, i);
        }
    }

    // Transpose of graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        for (auto nbr : adjList[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // DFS on transpose graph using topoSort
    int cnt = 0;
    while (!topoSort.empty())
    {
        int top = topoSort.top();
        topoSort.pop();

        if (!visited[top])
        {
            // count of how many strongly connected components are there
            cnt++;
            dfsForTranspose(transpose, visited, top);
        }
    }
    return cnt;
}

int main()
{
    return 0;
}