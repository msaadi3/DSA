#include <bits/stdc++.h>
using namespace std;

// Unique permutations
class Solution
{
    void solve(vector<int> &input, set<vector<int>> &set, int index)
    {
        // base case
        if (index >= input.size())
        {
            set.insert(input);
            return;
        }

        for (int i = index; i < input.size(); i++)
        {
            swap(input[index], input[i]);
            // recursive call
            solve(input, set, index + 1);

            // backtracking
            swap(input[index], input[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> set;
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, set, index);
        for (auto i : set)
        {
            ans.push_back(i);
        }
        return ans;
    }
};