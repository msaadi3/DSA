#include <bits/stdc++.h>
using namespace std;

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    // base case
    if (myStack.empty())
    {
        myStack.push(x);
        return myStack;
    }

    int top = myStack.top();
    myStack.pop();

    // recursive call
    pushAtBottom(myStack, x);

    // push that element back while returning from recursive calls
    myStack.push(top);

    return myStack;
}

int main()
{
    return 0;
}