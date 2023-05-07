#include <bits/stdc++.h>
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> ans;

    for (int i = 0; i < k; i++)
    {
        int front = q.front();
        q.pop();
        ans.push(front);
    }

    while (!ans.empty())
    {
        int top = ans.top();
        ans.pop();
        q.push(top);
    }

    int i = 0;
    while (i < q.size() - k)
    {
        int front = q.front();
        q.pop();
        q.push(front);
        i++;
    }
    return q;
}
