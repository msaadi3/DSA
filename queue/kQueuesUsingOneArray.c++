#include <bits/stdc++.h>
using namespace std;

class kQueues
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

public:
    kQueues(int n, int k)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freeSpot = 0;

        // Initialize front, rear and next arrays
        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        // update last index of next to -1
        next[n - 1] = -1;
    }

    void enqueue(int qn, int element)
    {
        // check overflow
        if (freeSpot == -1)
        {
            cout << "Queue ran out of space" << endl;
            return;
        }

        // Find index
        int index = freeSpot;

        // Update free spot
        freeSpot = next[index];

        // check if it's first value in queue
        if (front[qn - 1] == -1) // qn - 1 is becuase indexing is from zero so qn 1 means 1 - 1 = 0 that means 0 index represents first queue
        {
            front[qn - 1] = index; // didn't get it why we didn't update rare here
        }
        else
        {
            // Link new element to the previous element
            next[rear[qn - 1]] = index;
        }

        // Update next to -1 because this index is not free space anymore
        next[index] = -1;

        // Update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = element;
    }

    int dequeue(int qn)
    {
        // Check for underflow
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // Find index
        int index = front[qn - 1];

        // Update front
        front[qn - 1] = next[index];

        // manage free slot int the array
        next[index] = freeSpot; // didn't get it this line
        freeSpot = index;
        return arr[index];
    }
};

int main()
{
    kQueues q(10, 3);
    q.enqueue(1, 10);
    q.enqueue(1, 15);
    q.enqueue(2, 20);
    q.enqueue(1, 25);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    return 0;
}