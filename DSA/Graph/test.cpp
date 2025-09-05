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
    cin >> n;
    ll ans = 1;
    for (int i = 2; i * i <= n; i++) {
        int mu = 0;
        ll term = i;
        while (n % i == 0) {
            mu++;
            term *= i;
            n /= i;
        }
        if (mu)
            ans *= (ll)(term - 1) / (i - 1);
    }
    if (n != 1)
        ans *= (n + 1);
    cout << ans << "\n";
    return 0;
}