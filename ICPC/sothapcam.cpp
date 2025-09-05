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
vector<ll> ans;
void soThapCam(int maxx)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    //{so, tongcs}
    for (ll i = 1; i <= 9; i++)
        pq.push({ i, i });
    while (!pq.empty()) {
        auto [num, sum] = pq.top();
        pq.pop();
        for (int i = 0; i <= 9; i++) {
            if (sum + i < 10 && num * 10 + i < LONG_LONG_MAX) {
                pq.push({ num * 10 + i, sum + i });
            } else if (sum + i == 10) {
                ans.push_back(num * 10 + i);
            }
            if (ans.size() >= maxx) {
                return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int maxx = 0;
    int a[t + 1];
    for (int i = 1; i <= t; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    soThapCam(maxx);
    for (int i = 1; i <= t; i++)
        cout << ans[a[i] - 1] << "\n";

    return 0;
}
