#include <bits/stdc++.h>
using namespace std;

// T.C is O(9m) where m is the number of empty cells in sudoku and S.C is O(1) cuz matrix is 9 * 9 and we know max calls in stack could be 81

class Solution
{
    bool isSafe(vector<vector<char>> &board, char val, int row, int col)
    {
        for (int i = 0; i < 9; i++)
        {
            // row check
            if (board[row][i] == val)
            {
                return false;
            }

            // col check
            if (board[i][col] == val)
            {
                return false;
            }

            // 3 * 3 matrix check out of 9 * 9 matrix
            int subBoxRow = 3 * (row / 3) + i / 3;
            int subBoxCol = 3 * (col / 3) + i % 3;
            if (board[subBoxRow][subBoxCol] == val)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char val = '1'; val <= '9'; val++)
                    {
                        if (isSafe(board, val, row, col))
                        {
                            board[row][col] = val;
                            if (solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                // backtrack
                                board[row][col] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};