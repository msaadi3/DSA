#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto i : nums2)
        {
            if (s.erase(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}