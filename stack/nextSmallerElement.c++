#include <bits/stdc++.h>
using namespace std;

// This is much better
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && st.top() >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

// -----------
// And this is same as above but just with little tweaks but not that good
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
