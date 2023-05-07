#include <bits/stdc++.h>
using namespace std;

// subsequences of a string/integer or anything is 2^n where n is the size of the input

// SUBSEQUENCES OF A STRING

void solve(vector<string> &ans, string &str, string output, int index)
{
    if (index >= str.length())
    {
        if (output.length() > 0) // to not include empty subsequence in the answer
        {
            ans.push_back(output);
        }
        return;
    }

    // exclude
    solve(ans, str, output, index + 1);
    // include
    char element = str[index];
    output.push_back(element);
    solve(ans, str, output, index + 1);
}

vector<string> subsequences(string str)
{

    vector<string> ans;
    int index = 0;
    string output = "";
    solve(ans, str, output, index);
    return ans;
}
