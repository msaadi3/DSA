#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;
    int freeSpot;
    int n;
    int s;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        next = new int[s];
        top = new int[n];
        freeSpot = 0;

        // initialize top with -1
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // intialize next
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // update last index of next to -1
        next[s - 1] = -1;

        // initialize free spot
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Check for overflow
        if (freeSpot == -1)
        {
            return false;
        }

        // get index
        int index = freeSpot;

        // update free spot
        freeSpot = next[index];

        // push element
        arr[index] = x;

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Check for underflow
        if (top[m - 1] == -1)
        {
            return -1;
        }

        // Find index
        int index = top[m - 1];

        // update top
        top[m - 1] = next[index];

        // Manage free index

        // Update next
        next[index] = freeSpot;

        // Update freeSpot
        freeSpot = index;

        return arr[index];
    }
};
