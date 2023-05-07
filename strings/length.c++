#include <bits/stdc++.h>
using namespace std;

int lengthOfCharArr(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int lengthOfString(string arr)
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    // char arr[] = {"saad bin abi usama"};
    // char arr[] = {'s', 'a', 'a', 'd', ' ', ' '};
    // string arr = "saad bin abi usama";
    // int ans = lengthOfString(arr);
    // int ans = lengthOfCharArr(arr);
    // cout << ans;
    return 0;
}