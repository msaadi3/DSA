#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue; // Skip duplicates
        }
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == K)
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                {
                    j++; // Skip duplicates
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--; // Skip duplicates
                }
            }
            else if (sum < K)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}