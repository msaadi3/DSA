#include <bits/stdc++.h>
using namespace std;

void print(vector<char> &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}

int stringCompression(vector<char> &chars)
{
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();

    while (i < n)
    {
        int j = i;

        while (j < n && chars[i] == chars[j])
        {
            j++;
        }

        chars[ansIndex++] = chars[i];

        int count = j - i;
        if (count > 1)
        {
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }

        i = j;
    }

    return ansIndex;
}

int main()
{
    vector<char> input = {'a', 'a', 'b', 'b', 'b', 'c', 'c'};
    int ans = stringCompression(input);
    cout << ans;
    cout << endl;
    print(input);

    return 0;
}