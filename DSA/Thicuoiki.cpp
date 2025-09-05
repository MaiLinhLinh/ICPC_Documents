#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    ll x, y;
    cin >> n >> x >> y;
    ll l, r, ans;
    l = 0;
    r = 2e9 + 7;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll k = mid / x + mid / y;
        if (k >= n - 1) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans + min(x, y) << "\n";
}
