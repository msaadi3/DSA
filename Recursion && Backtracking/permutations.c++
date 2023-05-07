#include <bits/stdc++.h>
using namespace std;

// permutations of a string/integer or anything is n! where n is the size of the input

class Solution
{
    void solve(vector<int> &input, vector<vector<int>> &ans, int index)
    {
        // base case
        if (index >= input.size())
        {
            ans.push_back(input);
            return;
        }

        for (int i = index; i < input.size(); i++)
        {
            swap(input[index], input[i]);
            // recursive call
            solve(input, ans, index + 1);

            // backtracking
            swap(input[index], input[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};