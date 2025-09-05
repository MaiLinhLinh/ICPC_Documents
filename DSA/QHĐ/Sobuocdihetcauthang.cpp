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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int dp[n + 1] = { 0 }; // dp[i] la so cach buoc di den bac thu i
        dp[0] = 1;// 1 cách là không bước
        int prefixsum[n + 1] = { 0 };
        prefixsum[0] = 1; // prefixsum[i] là tổng số cách đi từ 0 đến i .prefixsum[i] = dp[i-1]+ dp[i-2]+..+dp[i-k] +... + dp[1]+ dp[0]
        for (int i = 1; i <= n; i++) {
            if (i <= k) // dp[i]= dp[0] + dp[1]+... + dp[i-1]
                dp[i] = prefixsum[i - 1] % mod;
            else { // dp[i] = dp[i-1]+ dp[i-2]+... + dp[i-k]
                dp[i] = (prefixsum[i - 1] - prefixsum[i - k - 1] + mod) % mod;
            }
            prefixsum[i] = (prefixsum[i - 1] + dp[i]) % mod;
        }
        cout << dp[n] << "\n";
    }
    return 0;
}