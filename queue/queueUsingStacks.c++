#include <bits/stdc++.h>
using namespace std;

// Implementing queue using just one stack. All operations are O(1) except of push function
/* You can implement queue using just one stack by either making push process costlier or pop costlier. Since we have two functions (top() and pop()) which require the top element of the stack, well make the push() function costlier - that is, for pushing a new element, we recursively pop the stack till it is empty and push it at the bottom of the stack, and take advantage of the recursive call to push back in the popped elements once the recursive call hits the base condition and returns. This implementation makes pop() and peek() functions easier. pop() is just going to pop off the top element in stack and peek() will return the top most element.*/
// Best approach 100/82

class MyQueue
{
    stack<int> stack;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        if (stack.size() == 0)
        {
            stack.push(x);
        }
        else
        {
            int top = stack.top();
            stack.pop();
            push(x);
            stack.push(top);
        }
    }

    int pop()
    {
        int popped = stack.top();
        stack.pop();
        return popped;
    }

    int peek()
    {
        return stack.top();
    }

    bool empty()
    {
        return stack.empty();
    }
};

// ----------------------

// same as above but without recursion / Not the best approach as 44/45
class MyQueue
{
    stack<int> s;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stack<int> temp;

        while (!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }

        s.push(x);

        while (!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
    }

    int pop()
    {
        int popped = s.top();
        s.pop();
        return popped;
    }

    int peek()
    {
        return s.top();
    }

    bool empty()
    {
        return s.empty();
    }
};

// -------------------

// using two stacks not the best approach as 44/44
class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int popped = s1.top();
        s1.pop();
        return popped;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};
