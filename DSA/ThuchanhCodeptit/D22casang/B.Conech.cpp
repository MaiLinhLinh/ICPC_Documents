#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int h[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    int dp[n + 1] = { 0 }; // nang luong min can tieu hao de nhay den i
    for (int i = 1; i <= n; i++)
        dp[i] = 1e9;
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= k) {
            for (int j = 1; j <= i - 1; j++) {
                dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j])); // dp[i] = min giữa dp[i] và dp[j] + năng lượng từ j nhay den i
            }
        } else {
            for (int j = i - k; j <= i - 1; j++)
                dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n] << "\n";
    return 0;
}