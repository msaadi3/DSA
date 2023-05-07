#include <bits/stdc++.h>
using namespace std;

// Shortest path in weighted undirected graph from source node to all other nodes
//  Dijkstra's Algorithm for shortest path
// T.C is O(ElogV)
// S.C is linear O(N) but if we include adjacency list then O(N + E)

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // creation of set on basis of (distance, node)
    // we can also use priority queue / min heap instead of set
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {

        // fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record
        st.erase(st.begin());

        // traverse on neighbiurs
        for (auto neighbours : adjList[topNode])
        {
            if (nodeDistance + neighbours.second < dist[neighbours.first])
            {

                auto record = st.find(make_pair(dist[neighbours.first], neighbours.first));
                if (record != st.end())
                {
                    st.erase(record);
                }

                // update distance vector
                dist[neighbours.first] = nodeDistance + neighbours.second;

                // push new record in set
                st.insert(make_pair(dist[neighbours.first], neighbours.first));
            }
        }
    }
    return dist;
}

int main()
{
    return 0;
}