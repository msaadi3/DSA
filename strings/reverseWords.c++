#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> stack;
        string result;

        for (int i = 0; i < s.length(); i++)
        {
            string word;
            if (s[i] == ' ')
            {
                continue;
            }
            while (i < s.length() && s[i] != ' ')
            {
                word += s[i];
                i++;
            }
            stack.push(word);
        }

        while (!stack.empty())
        {
            result += stack.top();
            stack.pop();
            if (!stack.empty())
            {
                result += " ";
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}