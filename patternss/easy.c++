#include <bits/stdc++.h>
using namespace std;
int main()
{

    /*
        int n;
        cin >> n;
        int count = 1;
        int i = 1;
        while (i <= n)
        {
            int j = 1;
            while (j <= n)
            {
                cout << count << " ";
                count++;
                j++;
            }
            cout << endl;
            i++;
        }
    */

    // same as above but with for loop

    /*
        int n;
        cin >> n;
        int count = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << count << " ";
                count++;
            }
            cout << endl;
        }
    */

    //_________________________________________________________________________________________________________________________________________

    // counting but in triangle

    /*
        int n;
        cin >> n;
        int row = 1;
        int count = 1;
        while (row <= n)
        {
            int col = 1;
            while (col <= row)
            {
                cout << count << " ";
                count++;
                col++;
            }
            cout << endl;
            row++;
        }


    */

    // same as above but with for loop

    /*
        int count = 1;
        int n;
        cin >> n;
        for (int row = 1; row <= n; row++)
        {
            for (int col = 1; col <= row; col++)
            {
                cout << count << " ";
                count++;
            }
            cout << endl;
        }


        */

    return 0;
}