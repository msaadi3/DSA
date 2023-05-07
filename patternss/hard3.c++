#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int spaces = row - 1;
        int col = 1;
        int counting = n - row + 1;
        while (col <= spaces)
        {
            cout << " ";
            col++;
        }
        col = 1;
        while (col <= counting)
        {
            // cout << counting << " ";
            cout << counting;
            col++;
        }
        cout << endl;
        row++;
    }

    /*
        int n;
        cin >> n;
        int row = 1;
        while (row <= n)
        {
            int spaces = row - 1;
            int col = 1;
            // int counting = n - row + 1;
            int counting = row - 1 + 1;
            while (col <= spaces)
            {
                cout << " ";
                col++;
            }
            // col = 1;
            while (col <= counting)
            {
                // cout << counting << " ";
                cout << counting;
                col++;
            }
            cout << endl;
            row++;
        }

    */

    return 0;
}