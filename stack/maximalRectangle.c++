#include <bits/stdc++.h>
using namespace std;

// Gotta see other approaches as well / Not satisfied but for later / Didn't get it

// GFG / TLE
class Solution
{
    vector<int> nextSmallerElement(int *heights, int n)
    {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(int *heights, int n)
    {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int *heights, int n)
    {
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int length = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            int newArea = length * width;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        if (n == 0 || m == 0)
        {
            return 0;
        }

        // Compute area for the first row
        int area = largestRectangleArea(M[0], m);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // Update row by adding preious row
                if (M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i - 1][j];
                }
                else
                {
                    M[i][j] = 0;
                }

                // entire row is updated now
                area = max(area, largestRectangleArea(M[i], m));
            }
        }
        return area;
    }
};

// ---------------------------------

// Leetcode just one error on run time / it was ok
class Solution
{
    vector<int> nextSmallerElement(vector<int> &heights, int n)
    {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &heights, int n)
    {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int length = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            int newArea = length * width;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (n == 0)
        {
            return 0;
        }

        // Convert char to int
        vector<int> intMatrix(m, 0);
        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == '1')
            {
                intMatrix[i] = 1;
            }
        }

        // Compute area for the first row
        int area = largestRectangleArea(intMatrix);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // Update row by adding preious row
                if (matrix[i][j] != '0')
                {
                    intMatrix[j] = matrix[i][j] - '0' + matrix[i - 1][j] - '0';
                }
                else
                {
                    intMatrix[j] = 0;
                }

                // entire row is updated now
                int newArea = largestRectangleArea(intMatrix);
                area = max(area, newArea);
            }
        }
        return area;
    }
};

// ---------------------------
// Leetcode just one error on run time / it was ok
class Solution
{
    vector<int> nextSmallerElement(vector<int> &heights, int n)
    {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &heights, int n)
    {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights, int n)
    {
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int length = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            int newArea = length * width;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (n == 0)
        {
            return 0;
        }

        vector<int> intMatrix(m, 0);
        int area = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (matrix[i][j] != '0')
                {
                    intMatrix[j]++;
                }
                else
                {
                    intMatrix[j] = 0;
                }

                int newArea = largestRectangleArea(intMatrix, m);
                area = max(area, newArea);
            }
        }
        return area;
    }
};

// Accepted on leetcode but from chatGPT

class Solution
{
    vector<int> nextSmallerElement(vector<int> &heights, int n)
    {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &heights, int n)
    {
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights, vector<int> &next, vector<int> &prev)
    {
        int n = heights.size();
        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int length = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            int newArea = length * width;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (n == 0)
        {
            return 0;
        }

        vector<int> intMatrix(m, 0);
        int area = 0;
        vector<int> next, prev;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (matrix[i][j] != '0')
                {
                    intMatrix[j]++;
                }
                else
                {
                    intMatrix[j] = 0;
                }
            }
            // calculate next and prev arrays for each row
            next = nextSmallerElement(intMatrix, m);
            prev = prevSmallerElement(intMatrix, m);
            int newArea = largestRectangleArea(intMatrix, next, prev);
            area = max(area, newArea);
        }
        return area;
    }
};
