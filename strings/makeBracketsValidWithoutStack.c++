#include <bits/stdc++.h>
using namespace std;

// Minimum Number of Swaps to Make the String Balanced without stack / Leetcode

class Solution
{
public:
    int minSwaps(string s)
    {
        int cnt = 0;

        for (char ch : s)
        {
            if (ch == '[')
            {
                cnt++;
            }
            else if (cnt)
            {
                cnt--;
            }
        }
        return (cnt + 1) / 2;
    }
};