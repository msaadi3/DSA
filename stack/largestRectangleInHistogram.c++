#include <bits/stdc++.h>
using namespace std;

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

public:
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
};