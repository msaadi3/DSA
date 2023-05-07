#include <bits/stdc++.h>
using namespace std;

// MY BRUTE FORCE APPROACH BUT TLE
string remAdjDub(string s)
{
    for (int i = 0; i + 1 < s.length(); i++)
    {
        if ((s[i] == s[i + 1]))
        {
            s.erase(i, 2);
            i = -1;
        }
    }
    return s;
}

// same as above but with while loop
string remAdjDub2(string s)
{
    int i = 0;
    while (i + 1 < s.length())
    {
        if ((s[i] == s[i + 1]))
        {
            s.erase(i, 2);
            i = -1;
        }
        i++;
    }
    return s;
}

// ---------------------------------------------------------------------

// ACCEPTED BUT GOT IT FROM LEETCODE DISCUSSION
string removeDuplicates(string s)
{

    int i = 1;
    string ans = "";
    ans.push_back(s[0]);
    while (i < s.length())
    {
        if (ans.back() == s[i])
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[i]);
        }
        i++;
    }

    return ans;
}

int main()
{
    return 0;
}
