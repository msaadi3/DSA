#include <bits/stdc++.h>
using namespace std;

// FIND SHORTEST PATH IN UNDIRECTED GRAPH USING BFS
// T.C && S.C IS LINEAR --> O(N + E)
// not accepted on coding ninjas after so many tries i don't why but i got the algo

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // Create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // DO BFS
    vector<bool> visited(n);
    vector<int> parent(n);
    queue<int> q;

    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    // PREPARE SHORTEST PATH
    vector<int> ans;
    int currentNode = t;
    ans.push_back(currentNode);
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;

    // if asked number of edges of shortest path
    /*
        int count = 0;
        int currentNode = t;
        while (currentNode != s)
        {
            currentNode = parent[currentNode];
            count++;
        }
        return count;
    */
}

// Same as above but with a little tweak as just i wrote two functions nothing else

/*

void shortestPathUsingBFS(unordered_map<int, list<int>>& adjList, vector<bool>& visited,
vector<int>& parent, queue<int>& q, vector<int>& ans, int s, int t){

    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
}

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // Create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }


    vector<bool> visited(n);
    vector<int> parent(n);
    queue<int> q;
    vector<int> ans;

    for(int i = 0; i < n; i++){
      if (!visited[i]) {
          shortestPathUsingBFS(adjList, visited, parent, q, ans, s, t);
      }
    }
    return ans;
}

*/
int main()
{
    return 0;
}