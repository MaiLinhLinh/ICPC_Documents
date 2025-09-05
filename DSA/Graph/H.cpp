#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
vector<pair<int, int>> adj[10007];
vector<int> visited(10007, 0);
vector<int> dist(1007, INT_MAX); // dist[i] la w bé nhất sao cho các cạnh trên đường đi đến i >= w;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e, st, end;
    cin >> v >> e >> st >> end;
    for (int i = 1; i <= e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }
    // dijkstra
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ dist[st], st });
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = 1;
        for (auto x : adj[u]) {
            int maxw = max(dist[u], x.second); // maxw là trọng số của cạnh lớn nhất trên đường đi đến x.first
            dist[x.first] = min(dist[x.first], maxw); // dist[x.first] là giá trị w bé nhất sao cho các cạnh <= w
            pq.push({ dist[x.first], x.first });
        }
    }
    if (dist[end] == INT_MAX) // không có đường đi đến end
        cout << "-1\n";
    else
        cout << dist[end] << "\n";
    return 0;
}
