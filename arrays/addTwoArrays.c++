#include <bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> input)
{
    int i = 0;
    int j = input.size() - 1;
    while (i < j)
    {
        swap(input[i++], input[j--]);
    }
    return input;
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    vector<int> ans;

    while ((i >= 0) && (j >= 0))
    {
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while (i >= 0)
    {
        int val1 = a[i];
        int sum = val1 + carry;

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    while (j >= 0)
    {
        int val2 = b[j];
        int sum = val2 + carry;

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    while (carry != 0)
    {
        int sum = carry;
        carry = carry / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    return reverse(ans);
}

int main()
{
    return 0;
}