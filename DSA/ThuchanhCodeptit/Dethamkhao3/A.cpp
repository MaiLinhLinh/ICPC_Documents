#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    string s[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    string t;
    cin >> t;
    int m;
    for (int i = 1; i <= n; i++) {
        if (s[i] == t) {
            m = i;
            break;
        }
    }
    int a[n + 2];
    for (int i = 1; i < n; i++) {
        if (i < m)
            a[i] = i;
        else {
            a[i] = i + 1;
        }
    }
    a[n] = m;
    set<vector<string>> se;
    do {
        vector<string> tmp;
        for (int i = 1; i <= n; i++) {
            tmp.push_back(s[a[i]]);
        }
        se.insert(tmp);
    } while (next_permutation(a + 1, a + n));

    for (auto x : se) {
        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }
    return 0;
}
