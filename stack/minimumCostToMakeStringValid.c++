#include <bits/stdc++.h>
using namespace std;

// Minimum bracket Reversal / Minimum cost to make a string valid

// Coding ninjas
int findMinimumCost(string str)
{
    // Odd case
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
        {
            s.push(ch);
        }
        else
        {
            // closed bracket
            if (!s.empty() && s.top() == '{')
            {
                // valid case
                s.pop();
            }
            else
            {
                // Invalid cse
                s.push(ch);
            }
        }
    }

    // Now the stack contains only invalid brackets

    int cntOfOpen = 0;
    int cntOfCLosed = 0;

    while (!s.empty())
    {
        if (s.top() == '{')
        {
            cntOfOpen++;
        }
        else
        {
            cntOfCLosed++;
        }
        s.pop();
    }

    int ans = ((cntOfOpen + 1) / 2) + ((cntOfCLosed + 1) / 2);
    return ans;
}
