#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e5 + 7)
using namespace std;
vector<pair<int, int>> adj[nmax];
vector<int> dist(nmax, 0);
void dfs(int u, int st)
{
    for (auto x : adj[u]) {
        int v = x.first;
        int w = x.second;
        if (v == st) // nếu đỉnh con trùng với đỉnh xuất phát thì bỏ qua( vì mình bắt đầu từ đỉnh st)
            continue;
        if (dist[v] == 0) {
            dist[v] = max(dist[u], w);
            dfs(v, st);
        } else if (dist[v] > max(dist[u], w)) {
            dist[v] = min(dist[v], max(dist[u], w));
            dfs(v, st);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e, st, end;
    cin >> v >> e >> st >> end;
    for (int i = 1; i <= e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    dfs(st, st);
    if (dist[end] == 0)
        cout << "-1\n";
    else
        cout << dist[end] << "\n";
    return 0;
}
