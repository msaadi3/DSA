#include <bits/stdc++.h>
using namespace std;

// PRINT
void printArr(int arr[][5], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// LINEAR SEARCH
int linearSearch(int arr[][5], int row, int col, int k)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == k)
            {
                cout << k << " found ";
                return 1;
            }
        }
    }
    cout << k << " not found ";
    return 0;
}

// ROW WISE SUM
void rowWiseSum(int arr[][5], int row, int col)
{
    // int *ans = new int[row];

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
        // ans[i] = sum;
    }
    // return ans;
}

// COL WISE SUM
void colWiseSum(int arr[][5], int row, int col)
{

    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}

// LARGEST ROW WISE SUM
void largestRowWiseSum(int arr[][5], int row, int col)
{
    int *ans = new int[row];

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
        ans[i] = sum;
    }

    // FIND MAXIMUM
    int maxi = -1;
    int index = -1;
    for (int i = 0; i < row; i++)
    {

        if (ans[i] > maxi)
        {

            maxi = ans[i];
            index++;
        }
    }
    cout << " largest row wise sum is " << maxi << " and its index is " << index << endl;
}
// GET INPUT
void getInput(int array[][5], int row, int col)
{
    cout << " please enter input " << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> array[i][j];
        }
    }
}
int main()
{
    int array[4][5] = {0};
    getInput(array, 4, 5);
    // printArr(array, 4, 5);
    // rowWiseSum(array, 4, 5);
    // colWiseSum(array, 4, 5);
    // linearSearch(array, 4, 5, 5);
    largestRowWiseSum(array, 4, 5);
    return 0;
}