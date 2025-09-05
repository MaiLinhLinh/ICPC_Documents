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
vector<vector<int>> adj(1005);
bool visited[1005];
int parent[1005];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    parent[u] = -1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
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
    while (t--) {
        memset(visited, 0, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        int n, m, u, v;
        cin >> n >> m >> u >> v;
        for (int i = 0; i <= n; i++)
            adj[i].clear();
        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(u);
        if (!visited[v])
            cout << "-1\n";
        else {
            int cnt = 0;
            while (v != -1) {
                cnt++;
                v = parent[v];
            }
            cout << cnt - 1 << "\n";
        }
    }

    return 0;
}
