
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
        // char ch = 'A' - row + 1;
        // char ch = 'A' + row + 1;
        char ch = 'A' + row - 1;

        while (col <= n)
        {
            cout << ch << " ";
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
            // char ch = 'A' - row + 1;
            // char ch = 'A' + row + 1;
            char ch = 'A' + row - 1;
            for (int col = 1; col <= n; col++)
            {
                cout << ch << " ";
            }
            cout << endl;
        }

        */
    // __________________________________________________________________________________________________________________________________________

    /*
        int n;
        cin >> n;
        int row = 1;
        while (row <= n)
        {
            int col = 1;
            while (col <= n)
            {
                char ch = 'A' + col - 1;
                cout << ch << " ";
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
            for (int col = 1; col <= n; col++)
            {
                char ch = 'A' + col - 1;
                cout << ch << " ";
            }
            cout << endl;
        }


    */

    //    ________________________________________________________________________________________________________________________________________

    /*    int n;
        cin >> n;

        int row = 1;
        char ch = 'A';
        while (row <= n)
        {
            int col = 1;
            while (col <= n)
            {
                cout << ch << " ";
                ch++;
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
        char ch = 'A';
        for (int row = 1; row <= n; row++)
        {
            for (int col = 1; col <= row; col++)
            {
                cout << ch << " ";
                ch++;
            }
            cout << endl;
        }
    */

    // ________________________________________________________________________________________________________________________________________

    // int n;
    // cin >> n;
    // for (int row = 1; row <= n; row++)
    // {
    //     for (int col = 1; col <= col; col++)
    //     {
    //         char ch = 'A' + row + col - 2;
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    // }

    // same as above but with while loop
    /*
    int n;
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            char ch = 'A' + row + col - 2;
            cout << ch << " ";
            col++;
        }
        cout << endl;
        row++;
    }
*/
    //---------------------------------------------------------------------------------------------------------------------------------------

    /*
        int n;
        cin >> n;
        int row = 1;
        while (row <= n)
        {
            int col = 1;
            char ch = 'A' + row - 1;
            while (col <= row)
            {
                cout << ch << " ";
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
            char ch = 'A' + row - 1;
            for (int col = 1; col <= row; col++)
            {
                cout << ch << " ";
            }
            cout << endl;
        }
    */

    // ______________________________________________________________________________________________________________________________________

    /*
        int n;
        cin >> n;
        int row = 1;
        char ch = 'A';
        while (row <= n)
        {
            int col = 1;
            while (col <= row)
            {
                cout << ch << " ";
                ch++;
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
        char ch = 'A';
        for (int row = 1; row <= n; row++)
        {
            for (int col = 1; col <= row; col++)
            {
                cout << ch << " ";
                ch++;
            }
            cout << endl;
        }
    */
    /*
        int n;
        cin >> n;
        int row = 1;
        while (row <= n)
        {
            // char ch = 'A' - row + 1;
            int col = 1;
            while (col <= row)
            {
                char ch = 'A' + row + col - 2;
                cout << ch << " ";
                col++;
            }
            cout << endl;
            row++;
        }
    */
    /*
        int n;
        cin >> n;
        int row = 1;
        while (row <= n)
        {
            int col = 1;
            char ch = 'A' + n - row;
            while (col <= row)
            {

                cout << ch << " ";
                ch++;
                col++;
            }
            cout << endl;
            row++;
        }
    */

    //    ------------------------------------------------------------------------------------------------------------------------------------

    /*
        int n;
        cin >> n;
        int row = 1;
        while (row <= n)
        {
            int space = n - row;

            while (space)
            {
                cout << " ";
                space--;
            }

            int col = 1;
            while (col <= row)
            {
                cout << "*";
                col++;
            }
            cout << endl;
            row++;
        }


    */

    // same as above but with for loop  / gotta see it later. / not done yet

    /*
    int n;
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        int space = n - row;
        for (int s = 1; s >= space; s--)
        {
            cout << "";
        }

        for (int col = 1; col <= row; col++)
        {
            cout << "*";
        }
        cout << endl;
    }

    */

    // _______________________________________________________________________________________________________________________________________

    /*

    int n;
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        int stars = n - row + 1;
        while (col <= stars)
        {
            cout << "*"
                 << " ";
            col++;
        }
        cout << endl;
        row++;
    }
*/

    // same as above but with for loop

    /**
        int n;
        cin >> n;
        for (int row = 1; row <= n; row++)
        {
            int stars = n - row + 1;
            for (int col = 1; col < stars; col++)
            {
                cout << "*"
                     << " ";
            }
            cout << endl;
        }

        */

    // _______________________________________________________________________________________________________________________________________

    /*
        int n;
        cin >> n;
        int row = 1;
        while (row <= n)
        {
            int spaces = row - 1;
            int col = 1;
            while (col <= spaces)
            {
                cout << " ";
                col++;
            }

            col = 1;
            int stars = n - row + 1;
            while (col <= stars)
            {
                cout << "*";
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
          int space = row - 1;
          int stars = n - row + 1;
          // cout << endl;
          for (int col = 1; col <= space; col++)
          {
              cout << " ";
          }
          // cout << endl;
          for (int col = 1; col <= stars; col++)
          {
              cout << "*";
          }
          // cout << endl;
      }
  */
    return 0;
}