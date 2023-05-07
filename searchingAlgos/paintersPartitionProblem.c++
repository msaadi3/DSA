#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<int> &boards, int k, int mid)
{
    int painters = 1;
    int boardSum = 0;

    for (int i = 0; i < boards.size(); i++)
    {
        if (boardSum + boards[i] <= mid)
        {
            boardSum += boards[i];
        }
        else
        {
            painters++;
            if (painters > k || boards[i] > mid)
            {
                return 0;
            }
            boardSum = boards[i];
        }
    }
    return 1;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int sum = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        sum += boards[i];
    }

    int start = 0;
    int end = sum;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (isPossible(boards, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
}
