#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
ll luythua(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll x = luythua(a, b / 2);
    if (b % 2 == 0)
        return ((x % mod) * (x % mod)) % mod;
    return ((a % mod) * (((x % mod) * (x % mod)) % mod)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll ans = luythua(n, k);
        cout << ans << "\n";
    }
    return 0;
}
