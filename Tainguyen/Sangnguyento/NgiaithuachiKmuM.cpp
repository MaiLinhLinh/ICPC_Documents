// Tìm số nguyên M
//  lớn nhất sao cho N!
//  chia hết cho K^M
// .
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int MAXA = 1e6 + 10;

void solve()
{
    int64_t n, k;
    cin >> n >> k;

    vector<pair<int64_t, int>> primes;

    for (int i = 2; 1ll * i * i <= k; i++) {
        int cnt = 0;
        while (k % i == 0) {
            cnt++;
            k /= i;
        }
        if (cnt)
            primes.emplace_back(i, cnt);
    }
    if (k > 1)
        primes.emplace_back(k, 1);

    int64_t ans = n;
    for (auto x : primes) {
        int64_t cnt = 0;
        for (int64_t i = n; i > 0; i /= x.first) {
            cnt += i / x.first;
        }
        ans = min(ans, cnt / x.second);
    }

    cout << ans << "\n";
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int test = 1;
    cin >> test;

    while (test--) {
        solve();
    }

    return (0 ^ 0);
}