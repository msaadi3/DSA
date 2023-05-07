#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int openBraces = 0, closedBraces = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                openBraces++;
            }
            else
            {
                if (openBraces > 0)
                {
                    openBraces--;
                }
                else
                {
                    closedBraces++;
                }
            }
        }
        return openBraces + closedBraces;
    }
};