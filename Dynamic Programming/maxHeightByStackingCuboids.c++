#include <bits/stdc++.h>
using namespace std;

// Done but didn't get it completly and look for other solutions on leet code
// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/solutions/?orderBy=most_votes&languageTags=cpp

class Solution
{
    bool check(vector<int> &base, vector<int> &newBox)
    {
        if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Copy + Paste from longest increasing subsequence / LIS tabulation's space optimized approach
    int LIS(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // Include
                int include = 0;
                if (prev == -1 || check(cuboids[curr], cuboids[prev]))
                {
                    include = cuboids[curr][2] /*2 means height*/ + nextRow[curr + 1];
                }
                // Exclude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        // sort all the dimensions of every cuboid
        for (auto &a : cuboids)
        {
            sort(a.begin(), a.end());
        }

        // sort all cuboids basis on w or l
        sort(cuboids.begin(), cuboids.end());

        // Longest increasing subsequence / LIS
        return LIS(cuboids);
    }
};
