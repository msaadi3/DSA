#include <bits/stdc++.h>
using namespace std;

// SHORTEST PATH IN WEIGHTED DIRECTED ACYCLIC GRAPH (WEIGHTED DAG)
// T.C && S.C is linear
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    void addEdge(int u, int v, int w)
    {
        pair<int, int> p = make_pair(v, w);
        adjList[u].push_back(p);
    }

    void print()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << ") ";
            }
            cout << endl;
        }
    }

    void dfs(vector<bool> &visited, stack<int> &topoSort, int node)
    {
        visited[node] = true;

        for (auto neighbour : adjList[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(visited, topoSort, neighbour.first);
            }
        }
        topoSort.push(node);
    }

    void getShortestPath(vector<int> &dist, stack<int> &topoSort, int src)
    {
        dist[src] = 0;

        while (!topoSort.empty())
        {
            int top = topoSort.top();
            topoSort.pop();

            if (dist[top] != INT_MAX)
            {
                for (auto i : adjList[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};
int main()
{
    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.print();

    // Topological sort
    int n = 6;
    vector<bool> visited(n, false);
    stack<int> topoSort;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(visited, topoSort, i);
        }
    }

    // Prepare distance vector
    int src = 1;
    vector<int> dist(n, INT_MAX);
    g.getShortestPath(dist, topoSort, src);

    // print
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}