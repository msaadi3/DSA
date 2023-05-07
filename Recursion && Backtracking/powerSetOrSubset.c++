#include <bits/stdc++.h>
using namespace std;

// POWER SET / Subsets

class Solution
{
    void powerSet(vector<int> &input, int index, vector<vector<int>> &ans, vector<int> output)
    {
        // base case
        if (index >= input.size())
        {
            ans.push_back(output);
            return;
        }

        // exclude
        powerSet(input, index + 1, ans, output);
        // include
        int element = input[index];
        output.push_back(element);
        powerSet(input, index + 1, ans, output);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int index = 0;
        vector<vector<int>> ans;
        vector<int> output;

        powerSet(nums, index, ans, output);
        return ans;
    }
};