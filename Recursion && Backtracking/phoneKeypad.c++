#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(string &digits, vector<string> &ans, string mapping[], string &output, int index)
    {
        // base case
        if (index >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digits, ans, mapping, output, index + 1);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
        {
            return ans;
        }

        int index = 0;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output;
        solve(digits, ans, mapping, output, index);
        return ans;
    }
};