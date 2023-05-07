#include <bits/stdc++.h>
using namespace std;

// DIDN'T GET IT, GOTTA UNDERSTAND LATER AND ANTICLOCKWISE APPROACH AND FOR OTHER MATRICES T0O NOT JUST 3 * 3
void rotate(vector<vector<int>> &matrix)
{
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

int main()
{
    return 0;
}