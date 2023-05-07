#include <bits/stdc++.h>
using namespace std;
// count number of set bits / 1. leetCode problem done
int numberOfSetBits(u_int32_t n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{
    return 0;
}