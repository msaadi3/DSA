#include <bits/stdc++.h>
using namespace std;

// best solution 100/50
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() == 1)
        {
            return false;
        }

        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                {
                    char top = st.top();
                    if (top == '(' && s[i] == ')' || top == '{' && s[i] == '}' || top == '[' && s[i] == ']')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            return true;
        }

        return false;
    }
};

int main()
{
    return 0;
}