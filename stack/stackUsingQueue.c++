#include <bits/stdc++.h>
using namespace std;

// Not the best approach as 34/78
class MyStack
{
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 1; i < q.size(); i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int front = q.front();
        q.pop();
        return front;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

// -------------------------------------
// Using two queues / better than above as 100/38
class MyStack
{
    queue<int> q1, q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int front = q1.front();
        q1.pop();
        return front;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

// ------------------

// Not the best approach as 34/38
class MyStack
{
    queue<int> q1, q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        if (q1.empty())
        {
            q1.push(x);
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            q2.push(x);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    int pop()
    {
        int front = -1;
        if (!q1.empty())
        {
            front = q1.front();
            q1.pop();
        }
        else
        {
            front = q2.front();
            q2.pop();
        }
        return front;
    }

    int top()
    {
        int front = 0;
        if (!q1.empty())
        {
            front = q1.front();
        }
        else
        {
            front = q2.front();
        }
        return front;
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

// -------------------

// Not the best approach as 34/38
class MyStack
{
    queue<int> q1, q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int popped = q1.front();
        q1.pop();
        return popped;
    }

    int top()
    {
        int front = q1.front();
        return front;
    }

    bool empty()
    {
        return q1.empty();
    }
};
