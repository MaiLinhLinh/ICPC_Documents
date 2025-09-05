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
    int n, M;
    cin >> n >> M;
    int w[n + 2], v[n + 2];
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    int dp[n + 1][M + 1] = {};// giá trị lớn nhất khi xét i đồ vật với cái túi size j.
    // BTCS
    for (int j = 1; j <= M; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    //
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            if (j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);// max cua lay va khong lay
        }
    }
    cout << dp[n][M] << "\n";
    return 0;
}
