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
            // counting for first triangle
            int col = 1;
            int firstTri = n - row + 1;
            while (col <= firstTri)
            {
                cout << col;
                col++;
            }


            // stars in the middle
            int stars = (row - 1) * 2;
            while (stars)
            {
                cout << "*";
                stars--;
            }

            // reverse counting for last triangle

            int i = col - 1;
            while (i != 0)
            {
                cout << i;
                i--;
            }
            cout << endl;
            row++;
        }

    */

    // same as above but with for loop

    int n;
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        // counting for first triangle
        int firstTri = n - row + 1;
        int col;
        for (col = 1; col <= firstTri; col++)
        {
            cout << col;
        }
        int i = col - 1;

        // printing stars

        int stars = (row - 1) * 2;
        for (; stars != 0; stars--)
        {
            cout << "*";
        }

        // counting for last triangle
        for (i; i != 0; i--)
        {
            cout << i;
        }
        cout << endl;
    }

    return 0;
}