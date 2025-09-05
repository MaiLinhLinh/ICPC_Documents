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
int a[nmax], b[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector<int> c;
    int i = 1, j = 1;
    while (i <= n && j <= m) {
        if (a[i] <= b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }
    if (i <= n) { // neu mang a con du
        for (int k = i; k <= n; k++)
            c.push_back(a[k]);
    } else if (j <= m) { // neu mang b con du
        for (int k = j; k <= m; k++)
            c.push_back(b[k]);
    }

    for (int k = 0; k < c.size(); k++)
        cout << c[k] << " ";
    cout << "\n";
    for (int k = 0; k < c.size(); k++) {
        if (mp[c[k]] != 0) {
            cout << "a";
            mp[c[k]]--;
        } else
            cout << "b";
    }
    return 0;
}
