#include <bits/stdc++.h>
using namespace std;

// Using recursion
void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int front = q.front();
    q.pop();

    reverse(q);

    q.push(front);
}

// Using stack
void reverse(queue<int> &q)
{
    stack<int> st;

    while (!q.empty())
    {

        int front = q.front();
        q.pop();

        st.push(front);
    }

    while (!st.empty())
    {

        int top = st.top();
        st.pop();

        q.push(top);
    }
}