#include <bits/stdc++.h>
using namespace std;

// Kruskal's Algorithm && Disjoint Set
// Disjoint set is a DS that is used to implement Kruskal's Algo(to find mst) and also for cycle detection and also to find whether the node is in the same component or not
// Minimum Spanning tree
// T.C is O(mlogm) && S.C is O(n)

// Initialize parent and rank
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find parent / Find set
// T.C is approximately O(1)
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
    // path compression
}

// Union by rank
// Union / Union set / merge
// T.C is approximately O(1)
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
// till here this is disjoint set
// comparator
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{

    // T.C is O(mlogm) && S.C is O(n)
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    // Kruskal's Algorithm

    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v)
        {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

int main()
{
    return 0;
}