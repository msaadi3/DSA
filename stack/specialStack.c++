#include <bits/stdc++.h>
using namespace std;

// Not the best approach as 15/23
class MinStack
{
    stack<int> s1, s2;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (s1.empty())
        {
            s1.push(val);
            s2.push(val);
        }
        else
        {
            s1.push(val);
            s2.push(min(val, s2.top()));
        }
    }

    void pop()
    {
        if (s1.empty())
        {
            return;
        }
        else
        {
            s1.pop();
            s2.pop();
        }
    }

    int top()
    {
        if (s1.empty())
        {
            return -1;
        }
        return s1.top();
    }

    int getMin()
    {
        return s2.top();
    }
};

// -------------------
// Not the best approach as 15/23
class MinStack
{
    stack<pair<int, int>> s;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push({val, val});
        }
        else
        {
            s.push({val, min(val, s.top().second)});
        }
    }

    void pop()
    {
        if (s.empty())
        {
            return;
        }
        else
        {
            s.pop();
        }
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }
};

// ---------------

// leetcode
class MinStack
{
    stack<long> s;
    long mini;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            mini = val;
        }
        else
        {
            if (val <= mini)
            {
                s.push(2LL * val - mini);
                mini = val;
            }
            else
            {
                s.push(val);
            }
        }
    }

    void pop()
    {
        if (s.empty())
        {
            return;
        }

        if (s.top() < mini)
        {
            mini = 2LL * mini - s.top();
        }

        s.pop();
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }

        if (s.top() < mini)
        {
            return mini;
        }

        return s.top();
    }

    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }
        return mini;
    }
};

// ---------------------

// Coding ninjas

class SpecialStack
{
    stack<int> s;
    int mini = INT_MAX;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        s.pop();

        if (curr > mini)
        {
            return curr;
        }

        int prevMini = mini;
        mini = 2 * mini - curr;
        return prevMini;
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }

        if (s.top() > mini)
        {
            return s.top();
        }
        else
        {
            return mini;
        }
    }

    bool isEmpty()
    {
        return s.empty();
    }

    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }
        return mini;
    }
};