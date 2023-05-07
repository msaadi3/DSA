#include <bits/stdc++.h>
using namespace std;

// Prim's Algo to find the minimum spanning tree
// T.C is O(N2) but it can be optimized to O(nlogn) if i use another DS for key to find the minimum everytime in O(1) and S.C is linear

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    vector<int> parent(n + 1, -1);
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);

    key[1] = 0;
    parent[1] = -1; // 1 is a source node here

    for (int i = 1; i <= n; i++)
    {

        int mini = INT_MAX;
        int u = 0;

        // find the min node
        for (int j = 1; j <= n; j++) // it can be done using priority_queue / min heap or other DS in O(1) but that's for another day
        {
            if (mst[j] == false && key[j] < mini)
            {
                u = j;
                mini = key[j];
            }
        }

        // mark min node in mst as true
        mst[u] = true;

        // check mini neighbours
        for (auto neighbours : adjList[u])
        {
            int v = neighbours.first;
            int w = neighbours.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}

int main()
{
    return 0;
}
