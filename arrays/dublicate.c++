#include <bits/stdc++.h>
using namespace std;

// FIND DUBLICATE

// Love babbar's solution accepted on coding ninjas but not on leetcode
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];
        }
        for (int i = 1; i < nums.size(); i++)
        {
            ans = ans ^ i;
        }

        return ans;
    }
};

// Another one / accepted on leetcode
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }

        return -1;
    }
};

// Another one // accepted on leetcode
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            auto check = s.insert(nums[i]);
            if (!check.second)
            {
                return nums[i];
            }
        }

        return -1;
    }
};

// Contains dublicates
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            auto check = s.insert(nums[i]);
            if (!check.second)
            {
                return true;
            }
        }
        return false;
    }
};

// another aproach
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // return nums.size() > set<int>(nums.begin(), nums.end()).size();
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }
};

// best approach
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};

// FIND ALL DUBLICATES
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {};
        }

        vector<int> dublicates;

        for (int i = 0; i < nums.size(); i++)
        {
            int element = abs(nums[i]) - 1;
            if (nums[element] > 0)
            {
                nums[element] = (-nums[element]);
            }
            else
            {
                // dublicate found
                dublicates.push_back(abs(nums[i]));
            }
        }
        return dublicates;
    }
};

// Another one

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (auto i : nums)
        {
            mp[i]++;
        }

        nums.clear();

        for (auto i : mp)
        {
            if (i.second >= 2)
            {
                nums.push_back(i.first);
            }
        }

        return nums;
    }
};

int main()
{

    return 0;
}
