#include <bits/stdc++.h>
using namespace std;

// coding ninjas question  successfully submitted but didn't get it's some lines  / first lecture of love babbar graph series : create and print adjacency list of undirected graph

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{

    vector<int> temp[n]; // ?
    for (int i = 0; i < m; i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        temp[u].push_back(v);
        temp[v].push_back(u);
    }

    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++)
    {
        adjList[i].push_back(i);

        for (int j = 0; j < temp[i].size(); j++) // ?
        {
            adjList[i].push_back(temp[i][j]); // ?
        }
    }
    return adjList;
}

// difference between vector<int> ans[v] and vector<int>(v)
int main()
{

    return 0;
}
