#include <bits/stdc++.h>
using namespace std;

// cycle detection in undirected graph using BFS
// T.C && S.C is linear O(N + E)
// not accepted on coding ninjas

bool isCyclicBFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node)
{
    // To keep track of parent nodes
    unordered_map<int, int> parent;
    queue<int> q;
    parent[node] = -1;
    visited[node] = 1;
    q.push(node);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adjList[frontNode])
        {
            if (visited[neighbour] == true && neighbour != parent[frontNode])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                q.push(neighbour);
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

// cycle detection in undirected graph using DFS
bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool ans = isCyclicDFS(neighbour, node, visited, adjList);
            if (ans)
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // for isCyclicBFS
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicBFS(adjList, visited, i);
            if (ans)
            {
                return "YES";
            }
        }
    }

    // for isCyclicDFS

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if (ans)
            {
                return "YES";
            }
        }
    }

    return "NO";
}

int main()
{
    return 0;
}