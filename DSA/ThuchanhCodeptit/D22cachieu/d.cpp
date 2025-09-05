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
vector<vector<int>> adj(100005);
vector<pair<int, int>> toado(100005);
bool visited[100005];
int min_x, min_y, max_x, max_y;
void dfs(int u)
{
    visited[u] = 1;
    auto [x, y] = toado[u];
    min_x = min(min_x, x);
    min_y = min(min_y, y);
    max_x = max(max_x, x);
    max_y = max(max_y, y);
    for (auto v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> toado[i].first >> toado[i].second;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        min_x = min_y = INT_MAX;
        max_x = max_y = 0;
        int cdai = 0, crong = 0;
        if (!visited[i]) {
            dfs(i);
            cdai = max_x - min_x;
            crong = max_y - min_y;
            ll cvi = (cdai + crong) * 2;
            ans = min(ans, cvi);
        }
    }
    cout << ans << "\n";

    return 0;
}
