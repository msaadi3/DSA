#include <bits/stdc++.h>
using namespace std;

// gotta try this in O(1) space / without using that ans string
string replaceSpaces(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else
        {
            ans.push_back(s[i]);
        }
    }

    return ans;
}

int main()
{
    string input;
    cout << " enter something " << endl;
    getline(cin, input);
    string answer = replaceSpaces(input);
    cout << answer;
    return 0;
}