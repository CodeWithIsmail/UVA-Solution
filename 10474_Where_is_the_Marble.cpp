#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q, i, count = 1;
    cin >> n >> q;
    if (n != 0 && q != 0)
    {
        do
        {
            int a[n], search;
            for (i = 0; i < n; i++)
                cin >> a[i];

            sort(a, a + n);
            map<int, int> find;
            for (i = 0; i < n; i++)
            {
                if (find[a[i]] == 0)
                    find[a[i]] = i + 1;
            }

            cout << "CASE# " << count << ":" << endl;
            while (q--)
            {
                cin >> search;
                find[search] ? cout << search << " found at " << find[search] : cout << search << " not found";
                cout << endl;
            }
            cin >> n >> q;
            count++;
        } while (n != 0 && q != 0);
    }
}