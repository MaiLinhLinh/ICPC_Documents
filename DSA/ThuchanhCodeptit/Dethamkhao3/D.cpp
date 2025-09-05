#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)

vector<vector<int>> adj(10005);
bool visited[10005];
void bfs(int u)
{
    queue<int> q;
    visited[u] = 1;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
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
    int n, m;
    cin >> n >> m;
    int degadd[1005]={0};
    int degsub[1005] ={0};
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        degsub[u]++;
        degadd[v]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (degadd[i] == 0) {
            cnt++;
            bfs(i);
        }
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            bfs(i);
        }
    }
    cout << cnt;

    return 0;
}
