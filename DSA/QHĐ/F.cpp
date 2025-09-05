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

    vector<int> a(n + 1), dp(n + 1, INT_MIN), cnt(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = -1000, dem = 1;
    dp[0] = cnt[0] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
        ans = max(ans, a[i]);
    for (int i = 1; i <= n; i++) {

        for (int j = max(0, i - k); j < i; j++) {
            if (dp[i] < dp[j] + a[i]) {
                dp[i] = dp[j] + a[i];
                cnt[i] = cnt[j] + 1; // vị trí đầu tiên có dp max luôn có số bước bé nhất
                // nếu có vị trí dp[j] + a[i] == dp[i] (dpMax) thì a[j] chắc chắn = 0
                // ví dụ
                // a      6   -1   -1    -3    0     3
                // dp     6    5    5     3    5     8
                // cnt    1    2    2     2    3     3
            }
        }
        if (dp[i] > ans) {
            ans = dp[i];
            dem = cnt[i];
        } else if (dp[i] == ans)
            dem = min(dem, cnt[i]);
    }

    cout << ans << ' ' << dem << '\n';

    return 0;
}
/*
 for (int i = 1; i <= n; i++) {

        for (int j = max(0, i - k); j < i; j++) {
            if (dp[i] < dp[j] + a[i]) {
                dp[i] = dp[j] + a[i];
                cnt[i] = cnt[j] + 1; 
            }
            else if(dp[i] == dp[j]+ a[i])
                cnt[i] = min(cnt[i], cnt[j] + 1);
        }
        if (dp[i] > ans) {
            ans = dp[i];
            dem = cnt[i];
        } else if (dp[i] == ans)
            dem = min(dem, cnt[i]);
    }


*/
