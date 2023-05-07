#include <bits/stdc++.h>
using namespace std;

int isPowerOf2(int n)
{
    int ans = 1;
    for (int i = 0; i <= 30; i++)
    {
        int ans = pow(2, i);
        if (ans == n)
        {
            return 1;
        }
    }
    return 0;
}

// Best approach / faster than 100% on leetcode
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 1)
        {
            return true;
        }

        long ans = 1;

        for (int i = 0; i <= 30; i++)
        {

            ans = ans * 2;
            if (ans == n)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}