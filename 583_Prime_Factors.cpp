#include <bits/stdc++.h>
using namespace std;

const long long mx = 1e7 + 123;
bool isPrime[mx];
vector<long long> primes;

void primeGen(long long n)
{
    long long i, j;
    for (i = 3; i <= n; i += 2)
        isPrime[i] = true;
    isPrime[2] = true;
    for (i = 3; i <= sqrt(n); i += 2)
    {
        if (isPrime[i])
        {
            for (j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    primes.push_back(2);
    for (i = 3; i <= n; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}
vector<long long> primeFactorization(long long n)
{
    vector<long long> factors;
    for (auto x : primes)
    {
        if (x * x > n)
            break;
        if (n % x == 0)
        {
            while (n % x == 0)
            {
                n /= x;
                factors.push_back(x);
            }
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}
int main()
{
    long long n, i;
    primeGen(mx);
    for (;;)
    {
        cin >> n;
        if (!n)
            break;
        cout << n;
        n < 0 ? cout << " = -1 x " : cout << " = ";

        vector<long long> factors = primeFactorization(abs(n));
        for (i = 0; i < factors.size() - 1; i++)
            cout << factors[i] << " x ";
        cout << factors.back() << endl;
    }
}
