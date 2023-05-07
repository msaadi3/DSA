#include <bits/stdc++.h>
using namespace std;

// Using loops and using stacks approach is in the stacks folder

//  Nearest smaller element on the left side / Previous smaller element
class Solution
{
public:
    vector<int> leftSmaller(int n, int a[])
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            bool found = false;
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j] < a[i])
                {
                    ans.push_back(a[j]);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------------------
// Nearest greater element on the left side / Previous greater element
class Solution
{
public:
    vector<int> leftGreater(int n, int a[])
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            bool found = false;
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j] > a[i])
                {
                    ans.push_back(a[j]);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------------------
// Nearest greater element on the right side / next greater element

class Solution
{
public:
    vector<int> nextGreater(int n, int a[])
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            bool found = false;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] > a[i])
                {
                    ans.push_back(a[j]);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------------------
// Nearest smaller element on the right side / next smaller element

class Solution
{
public:
    vector<int> nextSmaller(int n, int a[])
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            bool found = false;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < a[i])
                {
                    ans.push_back(a[j]);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
