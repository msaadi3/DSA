#include <bits/stdc++.h>
using namespace std;

int invertBits(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int mask = 0;
    int m = n;

    while (m != 0)
    {
        mask = (mask << 1) | 1;
        m = (m >> 1);
    }
    int ans = (~n) & (mask);
    return ans;
}

int main()
{
    return 0;
}