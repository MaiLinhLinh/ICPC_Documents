#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
ll dp[nmax]; // dp[x] la gtri lon nhat co the lay duoc o tui kich co x
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int w[n + 1], v[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) { // vat
            for (int j = w[i]; j <= m; j++) { // kich co cua tui
                dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
            }
        }
        cout << dp[m] << "\n";
    }
    return 0;
}
