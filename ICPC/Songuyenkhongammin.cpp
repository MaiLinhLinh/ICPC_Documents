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
    int n, m;
    cin >> n >> m;
    int a[300005];
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        int x;
        cin >> x;
        for (int i = 1; i <= n; i++) {
            if (mp.count(a[i])) {
                mp.erase(a[i]);
            }
        }
        for (int i = 1; i <= n; i++) {

            a[i] = a[i] ^ x;

            mp[a[i]] = a[i];
        }

        for (int i = 0; i <= 300002; i++) {
            if (mp.count(i) == 0) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
