#include <bits/stdc++.h>
using namespace std;

// arr[i]/i[arr] = *(arr + i)
int getSum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int *i = new int;
    char *ch = new char;
    char *array = new char[10];
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    delete[] arr;
    return 0;
}