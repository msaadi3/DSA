#include <bits/stdc++.h>
using namespace std;

char maxOccChar(string s)
{
    int arr[26] = {0};
    int number = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a') && (s[i] <= 'z'))
        {
            number = s[i] - 'a';
            arr[number]++;
        }

        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            number = s[i] - 'A';
            arr[number]++;
        }
    }

    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > maxi)
        {
            ans = i;
            maxi = arr[i];
        }
    }
    if (maxi == 0) // additinal
    {
        cout << "there isn't any character that is occuring more than once";
        return '0';
    }

    return ans + 'a';
}

int main()
{
    string input;
    cout << " enter something " << endl;
    cin >> input;
    char ans = maxOccChar(input);
    cout << ans;
    return 0;
}