#include <bits/stdc++.h>
using namespace std;

class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        arr = new int[s];
        top1 = -1;
        top2 = s;
        size = s;
    }

    // Push in stack 1.
    void push1(int num)
    {
        // stack overflow
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = num;
        }
        else
        {
            return;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Stack overflow
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = num;
        }
        else
        {
            return;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Stack underflow
        if (top1 == -1)
        {
            return -1;
        }
        int popped = arr[top1];
        top1--;
        return popped;
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Stack underflow
        if (top2 == size)
        {
            return -1;
        }
        int popped = arr[top2];
        top2++;
        return popped;
    }
};
