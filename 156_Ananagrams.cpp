#include <bits/stdc++.h>
using namespace std;
string lowerSorted(string x)
{
    string ans = x;
    for (int i = 0; i < x.size(); i++)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int i;
    vector<string> input;
    map<string, int> find;

    string temp;
    cin >> temp;
    while (temp != "#")
    {
        input.push_back(temp);
        find[lowerSorted(temp)]++;
        cin >> temp;
    }

    sort(input.begin(), input.end());
    for (auto x : input)
    {
        if (find[lowerSorted(x)] == 1)
            cout << x << endl;
    }
}