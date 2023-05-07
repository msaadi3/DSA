#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    queue<int> temp;
    int n = q.size();

    for (int i = 0; i < n / 2; i++)
    {
        // int front = q.front();
        // q.pop();
        // temp.push(front);

        temp.push(q.front());
        q.pop();
    }

    while (!temp.empty())
    {
        // int frontTemp = temp.front();
        // temp.pop();
        // q.push(frontTemp);

        q.push(temp.front());
        q.push(q.front());

        q.pop();
        temp.pop();

        // int frontQ = q.front();
        // q.pop();
        // q.push(frontQ);
    }
}