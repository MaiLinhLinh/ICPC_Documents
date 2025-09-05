#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
vector<int> visited(nmax);
vector<int> adj[nmax];
int check;
vector<int> v;
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while (!q.empty()) {
        int dinh = q.front();
        q.pop();
        v.push_back(dinh);
        for (auto c : adj[dinh]) {
            if (!visited[c]) {
                q.push(c);
                visited[c] = 1;
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
        int n, m;
        cin >> n >> m;
        fill(adj, adj + nmax, vector<int> {});
        fill(visited.begin(), visited.end(), 0);
        v.clear();
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(1);
        int c1 = v[v.size() - 1];
        v.clear();
        bfs(n);
        int c2 = v[v.size() - 1];
        cout << c2 - c1 << "\n";
    }
    return 0;
}
