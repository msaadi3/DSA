#include <bits/stdc++.h>
using namespace std;

// Minimum time to burn the tree from target node

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// T.C is i think so O(NlogN) because we used map here and map has T.C of O(logN) but if i use unordered_map here then T.C could be O(N) because unordered_map T.C is O(1) and the S.C is O(N)

class Solution
{

    // Create mapping of node to parent and return the target node where to start
    Node *createMappingAndFindTarget(Node *root, map<Node *, Node *> &nodeToParent, int target)
    {
        // Using level order traversal
        Node *node = NULL;
        queue<Node *> q;
        q.push(root);
        nodeToParent[root] == NULL;

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            if (front->data == target)
            {
                node = front;
            }

            if (front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            if (front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return node;
    }

    // Burn the tree
    int burnTheTree(Node *start, map<Node *, Node *> &nodeToParent)
    {

        // Using level order traversal
        map<Node *, bool> visited;
        queue<Node *> q;
        int timer = 0;

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            bool flag = false;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();

                if (front->left && !visited[front->left])
                {
                    visited[front->left] = true;
                    q.push(front->left);
                    flag = true;
                }

                if (front->right && !visited[front->right])
                {
                    visited[front->right] = true;
                    q.push(front->right);
                    flag = true;
                }

                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                    flag = true;
                }
            }
            if (flag)
            {
                timer++;
            }
        }
        return timer;
    }

public:
    int minTime(Node *root, int target)
    {

        // Algo:
        // Create node to parent mapping
        // Find the target node
        // Burn the tree and return ans

        map<Node *, Node *> nodeToParent;
        Node *targetNode = createMappingAndFindTarget(root, nodeToParent, target);

        // Burn the tree and return ans
        return burnTheTree(targetNode, nodeToParent);
    }
};
