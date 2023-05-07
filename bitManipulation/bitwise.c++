#include <bits/stdc++.h>
using namespace std;

int main()
{

    // BITWISE OPERATORS
    /*
        int a, b;
        cin >> a >> b;

        // AND / & operator returns 1 if both bits are 1 otherwise 0
        cout << " a & b : " << (a & b) << endl;

        // OR / | operator returns 1 if there's any bit is 1 otherwise 0
        cout << " a | b : " << (a | b) << endl;

        // NOT / ~ operator just inverts the bits
        cout << " ~a : " << ~a << endl;

        // XOR / ^ operator returns 1 if and only if one of two bits are 1 otherwise 0
        cout << " a ^ b : " << (a ^ b) << endl;
    */

    // BITS SHIFTING

    // in case of positive value padding occurs only of 0s and in case of negative values padding is dependent on compiler

    // LEFT SHIFT / << for most of the cases or we can say for small values it is same as multiply with 2
    /*
        cout << (19 << 1) << endl;
        cout << (19 << 2) << endl;

        // RIGHT SHIFT / >> for most of the cases  it is same as divided by 2

        cout << (17 >> 1) << endl;
        cout << (17 >> 2) << endl;

      */

    // convert from decimal to binary
    // divide the number by 2 untill it becomes zero and store remainder at every step
    // at the end reverse the answer of remainders

    // convert from binary to decimal
    // 1     0      1      1      0       1
    // 2^5   2^4    2^3    2^2    2^1     2^0
    // ignore the zeros
    // 32 +         8+      4+             1       ==>  45

    // DECIMAL TO BINARY
    int n;
    cin >> n;

    int i = 0, ans = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        i++;
        n = n >> 1;
    }
    cout << ans;

    // conert -ve number to binary

    int n;
    cin >> n;

        // BINARY TO DECIMAL
    int n;
    cin >> n;
    int i = 0, ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if (digit == 1)
        {
            ans = ans + pow(2, i);
        }
        n = n / 2;
        i++;
    }
    cout << ans;

    return 0;
}