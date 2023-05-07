#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // to see whether the next move is safe or not
    bool isSafe(vector<string> &board, int n, int row, int col)
    {

        int x = row;
        int y = col;

        // row check
        while (y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }
            y--;
        }

        // No need to check for col because we are placing every queen in next col

        // diagonal check
        x = row;
        y = col;
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }

            x--;
            y--;
        }

        // diagonal check
        x = row;
        y = col;
        while (x < n && y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }

            x++;
            y--;
        }

        return true;
    }

    void solve(vector<string> &board, vector<vector<string>> &ans, int n, int col)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(board, n, row, col))
            {
                board[row][col] = 'Q';

                // recursive call
                solve(board, ans, n, col + 1);

                // backtracking
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(board, ans, n, 0);
        return ans;
    }
};

// More optimized

class Solution
{
    void solve(vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n, int col)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if ((leftRow[row] == 0) && (lowerDiagonal[row + col] == 0) && (upperDiagonal[n - 1 + col - row] == 0))
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // recursive call
                solve(board, ans, leftRow, upperDiagonal, lowerDiagonal, n, col + 1);

                // backtracking
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(board, ans, leftRow, upperDiagonal, lowerDiagonal, n, 0);
        return ans;
    }
};