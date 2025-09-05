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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n >> u >> v;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll pre[n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    deque<int> dq;
    ll ans = LLONG_MIN;
    for (int i = u; i <= n; i++) {
        while (!dq.empty() && pre[dq.back()] > pre[i - u])
            dq.pop_back();
        while (!dq.empty() && dq.front() < i - v)
            dq.pop_front();
        dq.push_back(i - u);
        ans = max(ans, pre[i] - pre[dq.front()]);
    }
    cout << ans << "\n";

    return 0;
}
