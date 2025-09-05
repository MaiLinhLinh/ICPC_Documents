#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
#define w first
#define d second.first
#define h second.second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pair<int, pair<int, int>> pii[n + 1];
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        pii[i] = { x, { y, z } };
    }
    sort(pii + 1, pii + n + 1, greater<pair<int, pair<int, int>>>());
    int dp[n + 1]; // dp[i] chieu cao lon nhat khi xep hop thu i lam dinh
    for (int i = 1; i <= n; i++)
        dp[i] = pii[i].h;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (pii[i].w < pii[j].w && pii[i].d < pii[j].d) {
                dp[i] = max(dp[i], dp[j] + pii[i].h);
            }
        }
    }
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}
