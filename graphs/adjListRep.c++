#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    // Create Adjacency List
    void addEdge(int u, int v, bool direction)
    {
        // direction == 0 -> undirected graph
        // direction == 1 -> directed graph

        adjList[u].push_back(v);

        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    // Print Adjacency List

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }

            cout << endl;
        }
    }
};

int main()
{
    int n, v = 0;
    cout << " enter number of nodes " << endl;
    cin >> n;
    cout << " enter number of edges " << endl;
    cin >> v;

    Graph g;
    for (int i = 0; i < v; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}