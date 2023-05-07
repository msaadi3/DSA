#include <bits/stdc++.h>
using namespace std;

// 2D ARRAY / MATRIX SORTED ROW WISE AND COL WISE TOO SO BINARY SEARCH ISN'T POSSIBLE THERE

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];

        if (element == target)
        {
            return 1;
        }

        if (element > target)
        {
            colIndex--;
        }
        else
        {
            rowIndex++;
        }
    }

    return 0;
}

int main()
{
    return 0;
}