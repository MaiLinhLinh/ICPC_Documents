#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// b - a[i] < k => b < a[i] + k => tim >= a[i] + k
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll idx = lower_bound(a, a + n, a[i] + k) - a;
        idx--;
        ans += idx - i;
    }
    cout << ans << "\n";
    return 0;
}
