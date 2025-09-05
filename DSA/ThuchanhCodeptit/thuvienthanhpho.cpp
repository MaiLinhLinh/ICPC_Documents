#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> adj(100005);
bool visited[100005];
int mincost = 1e9;
int a[100005];
void dfs(int u){
    visited[u] = 1;
    mincost = min(mincost, a[u]);
    //cout << mincost << "\n";
    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            mincost = 1e9;
            dfs(i);
            ans += mincost;
        }
    }
    cout << ans << "\n";
    return 0;
}
