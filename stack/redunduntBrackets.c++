#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRedundunt = true;
                while (st.top() != '(')
                {
                    if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                    {
                        isRedundunt = false;
                    }
                    st.pop();
                }
                if (isRedundunt)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}