#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, j;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];

        for (i = 0; i < 1000; i++)
        {
            int check = 0, temp = a[0];
            for (j = 0; j < n - 1; j++)
                a[j] = abs(a[j] - a[j + 1]);
            a[n - 1] = abs(temp - a[n - 1]);
            
            for (j = 0; j < n; j++)
            {
                if (a[j] != 0)
                    check = 1;
            }
            if (!check)
            {
                ans = 1;
                break;
            }
        }
        ans ? cout << "ZERO" : cout << "LOOP";
        cout << endl;
    }
}