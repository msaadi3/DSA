#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &stack, int element)
{
    if (stack.empty() || (!stack.empty() && stack.top() <= element))
    {
        stack.push(element);
        return;
    }

    int n = stack.top();
    stack.pop();

    insert(stack, element);

    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int top = stack.top();
    stack.pop();

    sortStack(stack);

    insert(stack, top);
}

int main()
{
    return 0;
}