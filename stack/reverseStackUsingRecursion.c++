#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &stack, int top)
{
    if (stack.empty())
    {
        stack.push(top);
        return;
    }

    int element = stack.top();
    stack.pop();

    insertAtBottom(stack, top);

    stack.push(element);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int top = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, top);
}

int main()
{
    return 0;
}