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
    int a[n + 1], b[m + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        int l = lower_bound(a + 1, a + n + 1, b[i]) - a;
        int r = upper_bound(a + 1, a + n + 1, b[i]) - a;
        ans += 1ll * (r - l);
    }
    cout << ans << "\n";
    return 0;
}
