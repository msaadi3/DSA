#include <bits/stdc++.h>
using namespace std;

// Time complexity and space complexity is O(N + E). N means no of nodes/vertices and E means number of edges

void prepareAdjList(vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adjList)
{

    for (int i = 0; i < edges.size(); i++)
    {
        // if edges was vector of vector not pair of vector
        // int u = edges[i][0];
        // int v = edges[i][1];

        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {

        int frontNode = q.front();
        q.pop();

        // store front node in ans;
        ans.push_back(frontNode);

        // Traverse all the neighbors of the front node
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(edges, adjList);

    // Traverse all the components of the graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main()
{
    return 0;
}