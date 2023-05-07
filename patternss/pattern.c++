
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n;
    // cin >> n;
    // for (int row = 1; row <= n; row++)
    // {
    //     for (int col = 1; col <= row; col++)
    //     {
    //         cout << row << " ";
    //     }
    //     cout << endl;
    // }

    // same as above but with while loop

    int n;
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << row << " ";
            col++;
        }
        cout << endl;
        row++;
    }

        return 0;
}