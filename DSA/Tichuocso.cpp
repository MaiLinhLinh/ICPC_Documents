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
    if (b % 2)
        return ((a % mod) * (((x % mod) * (x % mod)) % mod)) % mod;
    return ((x % mod) * (x % mod)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    map<ll, ll> mp;
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll tich = 1, cnt = 1;
    for (auto x : mp)
        cnt *= (x.second + 1);
    for (auto x : mp) {
        ll m = x.second;
        ll b = m * (m + 1) / 2;
        ll a = x.first;
        // ll tmp = luythua(a, b);
        ll c = cnt / (x.second + 1);
        tich = (tich * luythua(a, b * c)) % mod;
    }
    cout << tich << "\n";
    return 0;
}
