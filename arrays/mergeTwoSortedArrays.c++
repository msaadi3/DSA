#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &v1, vector<int> v2)
{
    int n1 = v1.size();
    int n2 = v2.size();

    int i = 0;
    int j = 0;

    vector<int> ans;
    while (i < n1 && j < n2)
    {
        if (v1[i] < v2[j])
        {
            ans.push_back(v1[i++]);
        }
        else
        {
            ans.push_back(v2[j++]);
        }
    }

    while (i < n1)
    {
        ans.push_back(v1[i++]);
    }

    while (j < n2)
    {
        ans.push_back(v2[j++]);
    }

    return ans;
}

int main()
{
    return 0;
}