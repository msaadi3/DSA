#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }

        return st.size();
    }
};

int main()
{
    return 0;
}