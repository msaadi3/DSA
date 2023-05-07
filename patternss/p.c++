
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
        int col = 1;
        int val = row;
        while (col <= row)
        {
            cout << val << " ";
            val++;
            col++;
        }
        cout << endl;
        row++;
    }
*/
    // same as above but with for loop

    /*
    int n;
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        int val = row;
        for (int col = 1; col <= row; col++)
        {
            cout << val << " ";
            val++;
        }
        cout << endl;
    }
*/
    // think about another method to solve this without using that extra variable (val)

    // _________________________________________________________________________________________________________________________________

    /*
        int n;
        cin >> n;
        int row = 1;
        while (row <= n)
        {
            int val = row;
            int col = 1;
            while (col <= row)
            {
                cout << val << " ";
                val--;
                col++;
            }
            cout << endl;
            row++;
        }
    */

    // same as above but with for loop

    /*
        int n;
        cin >> n;
        for (int row = 1; row <= n; row++)
        {
            int val = row;
            for (int col = 1; col <= row; col++)
            {
                cout << val << " ";
                val--;
            }
            cout << endl;
        }


    */

    // same as above but without usint that variable (val) / another aproach

    /*
        int n;
        cin >> n;
        for (int row = 1; row <= n; row++)
        {
            for (int col = 1; col <= row; col++)
            {
                cout << row - col + 1 << " ";
            }
            cout << endl;
        }

        */

    return 0;
}