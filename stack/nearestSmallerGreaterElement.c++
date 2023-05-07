#include <bits/stdc++.h>
using namespace std;

// Using stacks and using loops approach is in the arrays folder

//  Nearest smaller element on the left side / Previous smaller element
class Solution
{
public:
    vector<int> leftSmaller(int n, int a[])
    {
        vector<int> ans;
        stack<int> smallerElements;

        for (int i = 0; i < n; i++)
        {
            while (!smallerElements.empty() && smallerElements.top() >= a[i])
            {
                smallerElements.pop();
            }

            if (smallerElements.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(smallerElements.top());
            }
            smallerElements.push(a[i]);
        }

        return ans;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------------------
// Nearest greater element on the left side / Previous greater element
class Solution
{
public:
    vector<int> leftgreater(int n, int a[])
    {
        vector<int> ans;
        stack<int> greaterElements;

        for (int i = 0; i < n; i++)
        {
            while (!greaterElements.empty() && greaterElements.top() <= a[i])
            {
                greaterElements.pop();
            }

            if (greaterElements.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(greaterElements.top());
            }
            greaterElements.push(a[i]);
        }

        return ans;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------------------
// Nearest greater element on the right side / next greater element

class Solution
{
public:
    vector<int> rightGreater(int n, int a[])
    {
        vector<int> ans;
        stack<int> greaterElements;

        for (int i = n - 1; i >= 0; i++)
        {
            while (!greaterElements.empty() && greaterElements.top() <= a[i])
            {
                greaterElements.pop();
            }

            if (greaterElements.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(greaterElements.top());
            }
            greaterElements.push(a[i]);
        }

        return ans;
    }
};

// ----------------------------------------------------------------------------------------------------------------------------------------
// Nearest smaller element on the right side / next smaller element

class Solution
{
public:
    vector<int> rightGreater(int n, int a[])
    {
        vector<int> ans;
        stack<int> smallerElements;

        for (int i = n - 1; i >= 0; i++)
        {
            while (!smallerElements.empty() && smallerElements.top() >= a[i])
            {
                smallerElements.pop();
            }

            if (smallerElements.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(smallerElements.top());
            }
            smallerElements.push(a[i]);
        }

        return ans;
    }
};
