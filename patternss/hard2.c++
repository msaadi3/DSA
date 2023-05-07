#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*
        int n;
        cin >> n;
        int row = 1;
        while (row <= n)
        {
            int spaces = n - row;
            int col = 1;
            while (col <= spaces)
            {
                cout << " ";
                col++;
            }

            col = 1;
            while (col <= row)
            {
                cout << col;
                col++;
            }

            int i = row - 1;
            while (i)
            {
                cout << i;
                i--;
            }

            // while (i <= row && i != 0)
            // {
            //     cout << i;
            //     i--;
            // }
            cout << endl;
            row++;
        }

    */
    // same as above but with for loop

    int n;
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        int spaces = n - row;
        int i = row - 1;
        for (int col = 1; col <= spaces; col++)
        {
            cout << " ";
        }

        for (int col = 1; col <= row; col++)
        {
            cout << col;
        }

        for (int col = i; col != 0; col--)
        {
            cout << col;
        }
        cout << endl;
    }

    return 0;
}