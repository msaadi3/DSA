#include <bits/stdc++.h>
using namespace std;

// T.C is O(4^n^2) and S.C is O(n*m)
class Solution
{
    void solveRateInMaze(vector<vector<int>> &maze, int n, int x, int y, vector<vector<bool>> &visited, vector<string> &ans, string path)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // 4 movement
        // DOWN, LEFT, RIGHT, UP (D,L,R,U)

        // DOWN
        if (x + 1 < n && maze[x + 1][y] == 1 && !visited[x + 1][y])
        {
            visited[x][y] = 1;
            solveRateInMaze(maze, n, x + 1, y, visited, ans, path + 'D');
            visited[x][y] = 0;
        }

        // LEFT
        if (y - 1 >= 0 && maze[x][y - 1] == 1 && !visited[x][y - 1])
        {
            visited[x][y] = 1;
            solveRateInMaze(maze, n, x, y - 1, visited, ans, path + 'L');
            visited[x][y] = 0;
        }

        // RIGHT
        if (y + 1 < n && maze[x][y + 1] == 1 && !visited[x][y + 1])
        {
            visited[x][y] = 1;
            solveRateInMaze(maze, n, x, y + 1, visited, ans, path + 'R');
            visited[x][y] = 0;
        }

        // UP
        if (x - 1 >= 0 && maze[x - 1][y] == 1 && !visited[x - 1][y])
        {
            visited[x][y] = 1;
            solveRateInMaze(maze, n, x - 1, y, visited, ans, path + 'U');
            visited[x][y] = 0;
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 0)
        {
            return ans;
        }

        vector<vector<bool>> visited(n, vector<bool>(n, 0));

        string path = "";
        solveRateInMaze(m, n, 0, 0, visited, ans, path);
        return ans;
    }
};

// just shorten the same code
class Solution
{
    void solveRateInMaze(vector<vector<int>> &maze, int n, int i, int j, vector<vector<bool>> &visited, vector<string> &ans, string path, int di[], int dj[])
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // 4 movement
        // DOWN, LEFT, RIGHT, UP (D,L,R,U)

        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++)
        {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !visited[nexti][nextj] &&
                maze[nexti][nextj] == 1)
            {
                visited[i][j] = 1;
                solveRateInMaze(maze, n, nexti, nextj, visited, ans, path + dir[ind], di, dj);
                visited[i][j] = 0;
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 0)
        {
            return ans;
        }

        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        string path = "";
        solveRateInMaze(m, n, 0, 0, visited, ans, path, di, dj);
        return ans;
    }
};
