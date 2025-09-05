#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> visited(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 1;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 1)
            continue;
        // nếu đỉnh chưa được duyệt thì nó thuộc 1 nhóm mới
        ans = max(ans, cnt); // cập nhật kết quả
        // bfs với đỉnh chưa được duyệt
        queue<int> q;
        q.push(i);
        cnt = 1;
        visited[i] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto x : adj[u]) { // duyet cac đỉnh con
                if (visited[x] == 0) {
                    q.push(x);
                    cnt++;
                    visited[x] = 1;
                }
            }
        }
    }
    cout << max(ans, cnt);
    return 0;
}
