#include <bits/stdc++.h>
using namespace std;

// Bellman ford algo is used to find the shortest path provided there's no negative cycles. it is applied on directed graphs with -ve weights but it can also be applied on undirected graph
// Bellman ford algo can be used to find out if the graph has any negative cycles or not
// T.C is O(E * N) && S.C is linear

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // n-1 times
    for (int i = 1; i <= n; i++)
    {
        // traverse on edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + w < dist[v]))
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycles
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e9 && (dist[u] + w < dist[v]))
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        return dist[dest];
    }
    return -1;
}
int main()
{
    return 0;
}