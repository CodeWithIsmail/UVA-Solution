#include <bits/stdc++.h>
using namespace std;

const int mx = 1000000 + 1;
bool isPrime[mx];
vector<int> primes;
void sieve(int n)
{
    int i, j, limit = n + 1;

    for (i = 3; i <= limit; i += 2)
        isPrime[i] = true;
    isPrime[2] = true;
    for (i = 3; i <= sqrt(limit); i += 2)
    {
        if (isPrime[i])
        {
            for (j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (i = 2; i <= limit; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}
int main()
{
    int n;
    cin >> n;
    if (!n)
        return 0;
    sieve(mx);

    do
    {
        for (auto x : primes)
        {
            if (isPrime[n - x])
            {
                cout << n << " = " << x << " + " << n - x << endl;
                break;
            }
            if (x > n / 2)
            {
                cout << "Goldbach's conjecture is wrong." << endl;
                break;
            }
        }

        cin >> n;
    } while (n);
}