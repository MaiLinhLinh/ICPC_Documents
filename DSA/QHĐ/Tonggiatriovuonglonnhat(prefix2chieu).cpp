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
    int n, k;
    cin >> n >> k;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    ll dp[n + 1][n + 1] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
        }
    }
    ll ans = 0;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= n; j++) {
            ll sum = dp[i][j] - dp[i][j - k] - dp[i - k][j] + dp[i - k][j - k];
            ans = max(ans, sum);
        }
    }
    cout << ans << "\n";
    return 0;
}
