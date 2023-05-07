#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int col = 0; col < mCols; col++)
    {
        if (col & 1)
        {
            // odd case - bottom to top
            for (int row = nRows - 1; row >= 0; row--)
            {
                ans.push_back(arr[row][col]);
                // cout << arr[row][col] << " ";
            }
        }
        else
        {
            // 0 or even - top to bottom
            for (int row = 0; row < nRows; row++)
            {
                ans.push_back(arr[row][col]);
                // cout << arr[row][col] << " ";
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}