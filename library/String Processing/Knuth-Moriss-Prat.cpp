#include <bits/stdc++.h>
using namespace std;

int prefix_func(const string &pattern, vector <int> &pi)
{
    pi.resize(pattern.size());
    int now = -1; pi[0] = -1;

    for (int i = 1; i < pattern.size(); i++)
    {
        while (now != -1 and pattern[now+1] != pattern[i])
            now = pi[now];

        if (pattern[now+1] == pattern[i]) pi[i] = ++now;
        else pi[i] = now = -1;
    }
}

int main()
{
    int t, cn = 0, q;
    cin >> t;

    vector <int> pi;
    string txt, pat;

    while (++cn <= t)
    {
        cin >> q >> txt;
        cout << "Case " << cn << ":\n";

        while (q--)
        {
            cin >> pat;
            prefix_func(pat + "#" + txt, pi);
            cout << count(pi.begin(), pi.end(), pat.size()-1) << "\n";
        }
    }

    return 0;
}
