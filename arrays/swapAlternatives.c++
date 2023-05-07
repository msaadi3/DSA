
#include <bits/stdc++.h>
using namespace std;

// swap alternatives

void swapAlternatives(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {

            swap(arr[i], arr[i + 1]);
        }
    }
}

// SWAP
void mySwap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    return 0;
}