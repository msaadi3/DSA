#include <bits/stdc++.h>
using namespace std;

// Topological sort using DFS
// T.C && S.C is linear

void topoSort(unordered_map<int, list<int>> &adjList, vector<bool> &visited, stack<int> &s, int node)
{
    visited[node] = 1;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            topoSort(adjList, visited, s, neighbour);
        }
    }

    // push node into stack when function returns
    s.push(node);
}

vector<int> topologicalSortDFS(vector<vector<int>> &edges, int v, int e)
{
    // create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // unordered_map<int, bool> visited;
    vector<bool> visited(v); // use this instead of above to decrease T.C / to avoid tle
    stack<int> s;

    // traverse all the components
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSort(adjList, visited, s, i);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// ----------------------------------------

// Topological sort using BFS / Kahn's algorithm
// T.C and S.C is linear 0(N + E)

vector<int> topologicalSortBFS(vector<vector<int>> &edges, int v, int e)
{

    // create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // Find all Indegrees
    vector<int> indegree(v);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // push all the nodes in the queue that have 0 indegree
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Do BFS
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neighbour : adjList[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}