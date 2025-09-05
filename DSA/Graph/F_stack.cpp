#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e3 + 7)
using namespace std;
vector<int> adj[nmax];
vector<int> visited(nmax);
void dfs(int u)
{
    stack<int> stk;
    stk.push(u);
    visited[u] = 1;
    cout << u << " ";
    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();
        // duyet danh sach ke cua u
        for (int x : adj[v]) {
            if (visited[x] == 0) {
                cout << x << " ";
                stk.push(v);
                stk.push(x);
                visited[x] = 1;
                break;
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
        int v, e, st;
        cin >> v >> e >> st;
        fill(adj, adj + nmax, vector<int> {});
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
