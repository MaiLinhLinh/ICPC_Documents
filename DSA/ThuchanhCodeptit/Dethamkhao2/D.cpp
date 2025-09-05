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
void dfs(int u)
{
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
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

        int n, m, x, y;
        cin >> n >> m >> x >> y;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int cnt = 0;
        // diem nghen la diem xuat hien o moi duong di tu x den y => neu bo diem nghen di thi khong co duong di tu x den y
        for (int i = 1; i <= n; i++) {
            memset(visited, 0, sizeof(visited));
            if (i != x && i != y) {
                visited[i] = 1; // bo dinh i
                dfs(x);
                if (!visited[y])
                    cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
