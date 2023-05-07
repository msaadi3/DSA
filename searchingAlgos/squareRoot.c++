#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n)
{
    // sqaure root of any number lies between 0 to n/that number and that is called search space  so we can apply binary search here
    // range where answer lies is called search space and if that range is monotonc function / sorted(increasing or decreasing) we can apply binary search there
    // long long int is same as long long and it is same as long
    int start = 0;
    int end = n;
    long long int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        long long int square = mid * mid;

        if (square == n)
        {
            return mid;
        }

        if (square < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

double morePrecision(int n, int precision, int integerAns)
{
    double factor = 1;
    double ans = integerAns;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        // 0.1
        // 0.01
        // 0.001
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int number;
    cout << "enter number for squre root " << endl;
    cin >> number;
    int pre;
    cout << " how much precise you want " << endl;
    cin >> pre;
    int intAns = squareRoot(number);
    cout << " square root of " << number << " is " << morePrecision(number, pre, intAns) << endl;

    // cout << " size of long long int is " << sizeof(long long int);
    // cout << " size of long is " << sizeof(long);
    // cout << " size of double is " << sizeof(double);

    return 0;
}
