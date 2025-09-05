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
    ll s;
    cin >> n >> s;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int r = 1;
    ll tong = 0;
    ll ans = 1e7;
    bool check = 0;
    for (int l = 1; l <= n; l++) {
        while (r <= n && tong < s) {
            tong += a[r];
            r++;
        }

        // luc nay tong >= s với chỉ số cuối = r - 1
        if (tong >= s) {
            ans = min(ans, 1ll * (r - l));
        }
        // tong tru di a[l] de xet den l tiep theo
        tong -= a[l];
    }
    if (ans > n)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}
