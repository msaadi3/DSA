#include <bits/stdc++.h>
using namespace std;

// Longest common prefix question without trie and trie approach of this question is in trie folder
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";

        // for traversing all characters of first string
        for (int i = 0; i < strs[0].size(); i++)
        {
            char ch = strs[0][i];
            bool match = true;

            // for comparing ch with the rest of the strings
            for (int j = 1; j < strs.size(); j++)
            {
                // Not match
                if (strs[j].size() < 1 || ch != strs[j][i])
                {
                    match = false;
                    break;
                }
            }

            if (match != false)
            {
                ans.push_back(ch);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

// another approach
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty() || strs[0].empty())
        {
            return "";
        }

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        string ans = "";

        for (int i = 0; i < first.size(); i++)
        {
            if (first[i] != last[i])
            {
                break;
            }
            else
            {
                ans.push_back(first[i]);
            }
        }
        return ans;
    }
};
