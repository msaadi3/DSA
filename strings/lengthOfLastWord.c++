#include <bits/stdc++.h>
using namespace std;

// NOT THE BEST SOLUTION / GAVE ERROR ON LEETCODE ON SUBMISSION

/*
int lengthOfLastWord(string s)
{
    int n = s.length() - 1;
    int length = 0;
    while (s[n] == ' ')
    {
        n--;
    }
    while (s[n] != ' ')
    {
        length++;
        n--;
    }
    return length;
}
*/

int lengthOfLastWord(string s)
{
    stack<char> st;
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    while (st.top() == ' ')
    {
        st.pop();
    }

    while (!st.empty() || st.top() != ' ')
    {
        st.pop();
        count++;
    }
    return count;
}

int main()
{
    return 0;
}