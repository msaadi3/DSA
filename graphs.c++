/**

NODE: is just an entity to store data it cound be anything like chars,objects,int etc.
EDGE: is just the connection between nodes that is connecting two nodes

DIRECTED GREAPH: it is the graph in which all the edges are directed. Directed EDGES mean that just one node pointes/connects/links to the other node. In directed graph there are two types of degrees. i.e. indegree & outdegree.
    1.Indegree: number of edges that are incoming towards the node.
    2.Outdegree: number of edges that are outgoing from node towards other nodes.

UNDIRECTED GRAPH: it is the graph in which all the edges are undirected. UNDIRECTED EDGES mean that there are two edges between two nodes both are connecting/pointing to each other. In undirected graph there is a concept of DEGREE of a node. DEGREE OF UNDIRECTED GRAPH means how many edges are there of a node.

WEIGHTED GRAPH: it is the graph in which there's some sort of positive numerical value between/of edges and that value is called weight and that graph is called WEIGHTED GRAPH and if graph is not WEIGHTED and we need it to be WEIGHTED then we just assume 1 weight for every edge

CYCLIC GRAPH/CYCLE:

ACYCLIC GRAPH:


PATH:








*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// GRAPH REPRESENTATION THRUGH ADJECENCY LIST USING UNORDERED_MAP AND LIST
class graphs
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // 0 for undirected graph
        // 1 for directed graph

        // create an edge from u to v
        adj[u].push_back(v);

        // if undirected then create an edge from v to u too
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    vector<int> bfs(int node /*, unordered_map<int, list<int>> adj*/)
    {
        queue<int> q;
        map<int, bool> visited;
        vector<int> ans;

        // int node = adj.at(0);
        q.push(node);
        visited[node] = true;
        ans.push_back(node);
        cout << node << endl;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                ans.push_back(i);
                cout << i;
            }
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
        }

        // for disjoint graph

        list<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!visited[*it])
            {
                dfs(*it);
            }
        }

        return ans;
    }

    vector<int> dfs(int node)
    {
        map<int, bool> visited;
        vector<int> ans;

        cout << node << endl;
        visited[node] = 1;
        ans.push_back(node);

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                cout << i;
            }
        }

        // for disjoint graph / for seperated components

        list<int>::iterator it;

        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!visited[*it])
            {
                dfs(*it);
            }
        }
        return ans;
    }

    string isCyclicBFS(int node, int numberOfNodes)
    {
        queue<int> q;
        map<int, int> parent;
        map<int, bool> visited;

        q.push(node);
        parent[node] = -1;
        visited[node] = true;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto neighbour : adj[front])
            {
                if (visited[neighbour] = true && neighbour != parent[front])
                {
                    return "YES";
                }
                else if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }

        return "NO";

        // for disjoint graph
        for (int i = 0; i < numberOfNodes; i++)
        {
            if (!visited[i])
            {
                isCyclicBFS(i, numberOfNodes);
            }
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "--->";
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
    int edge;
    int node;
    cout << "enter the number of edges " << endl;
    cin >> edge;
    cout << "enter the number of nodes " << endl;
    cin >> node;

    graphs g;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    // g.printGraph();

    cout << "enter node for bfs " << endl;
    int n;
    g.bfs(n);

    cout << "enter node for dfs " << endl;
    int m;
    g.bfs(m);

    return 0;
}