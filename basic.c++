#include <bits/stdc++.h>
using namespace std;

// count number of primes

bool isPrime(int number)
{
    if (number <= 1)
    {
        return false;
    }

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int countPrimes(int n)
{
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            cnt++;
        }
    }
    return cnt;
}
// ---------------------------------------
int update(int a)
{
    a -= a;
    return a;
}
// POWER
int power(int a, int b)
{
    int ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans = ans * a;
    }
    return ans;
}

// ____________________________________________________________
int isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
// ____________________________________________________
void printCounting(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    return;
}
// ________________________________________
// nCr
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r)
{
    int numerator = factorial(n);
    int denominator = factorial(r) * factorial(n - r);
    int ans = numerator / denominator;
    // those above 3 lines of code is formula of nCr
    return ans;
}
//________________________________

// sum of array elements
int sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int main()
{
    /*
    int n;
    cin >> n;
    bool isPrime = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            // cout << n << " is not a prime number " << endl;
            isPrime = 0;
            break;
        }
    }

    if (isPrime == 0)
    {
        cout << n << " is not a prime number " << endl;
    }
    else
    {
        cout << n << " is a prime number " << endl;
    }

    // _________________________________________

    // leetcode problem
    int n;
    cin >> n;
    int sum = 0;
    int product = 1;
    int ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        sum = sum + digit;
        product = product * digit;
        n = n / 10;
    }
    ans = product - sum;
    cout << ans;
    // ___________________________________________________________________________________________

    // sum from 1 to n
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    // __________________________________________________

    // fibonacci series
    int n;
    cin >> n;

    int a = 0;
    cout << a << " ";
    int b = 1;
    cout << b << " ";
    for (int i = 1; i <= n; i++)
    {
        int ans = a + b;
        cout << ans;
        a = b;
        b = ans;
    }
*/
    // _______________________________________________________________________
    /*
    // CALCULATOR

    int a, b;
    char op;
    cout << "enter the value of a " << endl;
    cin >> a;
    cout << "enter the value of b " << endl;
    cin >> b;
    cout << "enter the operation that you want to perform " << endl;
    cin >> op;

    switch (op)
    {
    case '+':
        cout << " a + b is " << (a + b) << endl;
        break;
    case '-':
        cout << " a - b is " << (a - b) << endl;
        break;
    case '*':
        cout << " a * b is " << (a * b) << endl;
        break;
    case '/':
        cout << " a / b is " << (a / b) << endl;
        break;
    }

    */

    /*
         int num = 3;
         while (1)

         {
             switch (num)
             {
             case 1:
                 cout << " mein 1 hoon ";
                 break;
             case 2:
                 cout << " mein 2 hoon ";
                 break;
             case 3:
                 cout << " mein 3 hoon ";
                 exit(num);
             case 4:
                 cout << " mein 4 hoon ";
                 break;

             default:
                 cout << " mein default case hoon ";
                 break;
             }
         }

     */
    /*

        // for (int i = 0; i < 10; i++)
        // {
        //     if (i == 5)
        //     {
        //         continue;
        //     }

        //     cout << i << " ";
        // }
    */

    /*
        int num = 3;
        switch (num)
        {
        case 1:
            cout << " mein 1 hoon ";
            break;
        case 2:
            cout << " mein 2 hoon ";
            break;
        case 3:
            cout << " mein 3 hoon ";
            // continue;
        case 4:
            cout << " mein 4 hoon ";
            break;

        default:
            cout << " mein default case hoon ";
            break;
        }
    */

    // for (int i = 0; i <= 15; i++)  cover it later
    // {
    //     cout << i << " ";
    //     if (i & 1)
    //     {
    //         continue;
    //     }
    //     i += 2;
    // }

    // for (int i = 0; i <= 10; i++)
    // {
    //     for (int j = i; j <= 10; j++)
    //     {
    //         cout << i << " " << j
    //     }
    // cout << endl;
    // }

    for (int i = 0; i <= 5; i++)
    {
        for (int j = i; j <= 5; j++)
        {
            if (i + j == 10)
            {
                break;
            }
            cout << i << " " << j;
        }
        cout << endl;
    }

    // for (int i = 0; i <= 15; i += 2)
    // {
    //     cout << i << " ";
    //     if (i & 1)
    //     {
    //         continue;
    //     }
    //     i++;
    // }
}