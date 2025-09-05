#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
ll g[93]; // do dai
ll cnt[50]; // so luong a
void calc()
{
    g[0] = 1;
    g[1] = 1;
    for (int i = 2; i < 93; i++)
        g[i] = g[i - 1] + g[i - 2];

    cnt[0] = 1;
    cnt[1] = 0;
    for (int i = 2; i < 50; i++)
        cnt[i] = cnt[i - 1] + cnt[i - 2];
}
int Try(int n, int k)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    if (k <= g[n - 1])
        return Try(n - 1, k);
    return cnt[n - 1] + Try(n - 2, k - g[n - 1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calc();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = Try(n, k);
        cout << ans << "\n";
    }

    return 0;
}
