#include <bits/stdc++.h>
using namespace std;

// there are more solutions of this problem and obviously more optimized but for later
class Solution
{
    bool knows(vector<vector<int>> &M, int n, int a, int b)
    {
        if (M[a][b] == 1)
        {
            return true;
        }
        return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;

        // step 1: push all elements in the stack
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        // Step 2: Compare two elements
        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (knows(M, n, a, b))
            {
                // a knows b so discard a and push b in stack
                st.push(b);
            }
            else
            {
                // b knows a so discard b and push a in stack
                st.push(a);
            }
        }

        // Step 3: Single element in stack is a potential celeb so verify it
        int celeb = st.top();
        st.pop();

        // Row check
        for (int i = 0; i < n; i++)
        {
            if (M[celeb][i] != 0)
            {
                return -1;
            }
        }

        // Col check
        int oneCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][celeb] == 1)
                oneCount++;
        }

        if (oneCount != n - 1)
        {
            return -1;
        }

        return celeb;
    }
};

// Coding ninjas
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
int findCelebrity(int n)
{
    int candidate = 0;
    for (int i = 1; i < n; i++)
    {
        if (knows(candidate, i))
        {
            candidate = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != candidate && (knows(candidate, i) || !knows(i, candidate)))
        {
            return -1;
        }
    }
    return candidate;
}
