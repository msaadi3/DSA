#include <bits/stdc++.h>
using namespace std;

// sieve of eratosthenes
// count number of primes
int countPrimes(int n)
{
    int cnt = 0;
    if (n <= 1)
    {
        return cnt;
    }

    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = false;
            }
        }
    }

    return cnt;
}

int main()
{

    return 0;
}
