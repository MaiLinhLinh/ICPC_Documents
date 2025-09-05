#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
vector<int> adj[nmax];
vector<int> visited(nmax);
void dfs(int u)
{
    visited[u] = 1;
    cout << u << " ";
    for (auto x : adj[u]) {
        if (visited[x] == 0)
            dfs(x);
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
        int v, e, st;
        cin >> v >> e >> st;
        fill(adj, adj + nmax, vector<int> {}); // mang thuong voi cac phan tu la vecto
        fill(visited.begin(), visited.end(), 0);
        for (int i = 1; i <= e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= v; i++)
            sort(adj[i].begin(), adj[i].end());
        dfs(st);
        cout << "\n";
    }
    return 0;
}
