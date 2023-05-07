#include <bits/stdc++.h>
using namespace std;

// Cycle detection in directed graph using dfs, time complexity and space complexity is linear
// T.C => O(N + E)
// S.C => O(N)

bool isCyclicDFS(unordered_map<int, bool> &visited, unordered_map<int, bool> &visitedDFSCalls, unordered_map<int, list<int>> &adjList, int node)
{

    visited[node] = 1;
    visitedDFSCalls[node] = 1;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool answer = isCyclicDFS(visited, visitedDFSCalls, adjList, neighbour);
            {
                if (answer)
                {
                    return true;
                }
            }
        }
        else if (visitedDFSCalls[neighbour] == 1)
        {
            return true;
        }
    }
    visitedDFSCalls[node] = 0;
    return false;
}

// Cycle detection in directed graph using BFS / kahn's algo
// T.C && S.C is linear O(N + E)

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    // create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;  // ?
        int v = edges[i].second - 1; // ? accepted on coding ninjas with this little tweak mentioned in love babbar's video and this is only for coding ninja's question no need otherwise

        adjList[u].push_back(v);
    }

    // Find all Indegrees
    vector<int> indegree(n);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // push all the nodes in the queue that have 0 indegree
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Do BFS
    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        cnt++;

        for (auto neighbour : adjList[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    // if cnt == number of nodes that means it is a valid topological sort  and  we get valid topological sort only in DAG that's why returns false otherwise returns true

    if (cnt == n)
        return 0;
    else
        return 1;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    // create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;  // ?
        int v = edges[i].second - 1; // ? accepted on coding ninjas with this little tweak mentioned in love babbar's video and this is only for coding ninja's question no need otherwise

        adjList[u].push_back(v);
    }

    // vector<bool> visited;
    unordered_map<int, bool> visited;

    // vector<bool> visitedDFSCalls;
    unordered_map<int, bool> visitedDFSCalls;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(visited, visitedDFSCalls, adjList, i);
            if (ans)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    return 0;
}