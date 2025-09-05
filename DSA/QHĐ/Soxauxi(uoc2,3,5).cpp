#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e4 + 7)
using namespace std;
ll dp[nmax]; // dp[i] la so xau xi thu i
void solve()
{
    dp[1] = 1;
    for (int i = 2; i <= nmax; i++) { //  dp[i] la so > dp[i-1] va la so xau xi nho nhat
        dp[i] = LONG_LONG_MAX;
        for (int j = 1; j <= i - 1; j++) {
            if (dp[j] * 2 > dp[i - 1])
                dp[i] = min(dp[i], dp[j] * 2);
            if (dp[j] * 3 > dp[i - 1])
                dp[i] = min(dp[i], dp[j] * 3);
            if (dp[j] * 5 > dp[i - 1])
                dp[i] = min(dp[i], dp[j] * 5);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
