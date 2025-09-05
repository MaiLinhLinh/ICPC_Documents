#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e3 + 7)
using namespace std;

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
        vector<int> adj[nmax];
        vector<int> visited(nmax, 0);
        for (int i = 1; i <= e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        for (int i = 1; i <= v; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        queue<int> q;
        q.push(st);
        visited[st] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (auto x : adj[u]) {
                if (visited[x] == 0) {
                    q.push(x);
                    visited[x] = 1;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
