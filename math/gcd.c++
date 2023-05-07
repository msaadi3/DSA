#include <bits/stdc++.h>
using namespace std;

// gcd is same as hcf: means highest common factor of two numbers that that can divide both numbers completly and with remainder 0
// gcd(a , b) = gcd(a - b, b) || gcd(a , b) = gcd(a % b, b)
// eucid's algo / eucid's gcd algo
// relation of gcd with lcm : lcm(a , b) * gcd(a , b) = a * b

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }

    return a;
}

int main()
{
    return 0;
}
