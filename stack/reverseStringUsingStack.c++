#include <bits/stdc++.h>
using namespace std;

// Not the best solution to reverse the string but just another approach using stack
// stack property : reverse
string reverse(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    string ans = "";

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        ans.push_back(top);
    }
    return ans;
}
int main()
{
    return 0;
}