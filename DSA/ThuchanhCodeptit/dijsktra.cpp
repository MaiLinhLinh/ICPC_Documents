#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> adj[100005]; // mang luu dinh va trong so
void dijsktra(int start)
{
    vector<int> d(n + 1, 1e9); // luu khoang cach min tu start den dinh i
    d[start] = 0; // khoang cach tu start den start = 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // luu khoang cach, dinh
    pq.push({ 0, start });
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u])
            continue;
        for (auto x : adj[u]) {
            auto [v, w] = x;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w; // w la khoang cach tu u den v
                pq.push({ d[v], v });
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int start;
        cin >> n >> m >> start;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({ v, w });
            adj[u].push_back({ u, w });
        }
        dijsktra(start);
    }
    return 0;
}
