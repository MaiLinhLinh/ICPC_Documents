#include<bits/stdc++.h>
using namespace std;
int n, m;// n dinh m canh
// duyet dfs thuan luu thu tu duyet vao stack, pop stack duyet dfs nguoc dem tplt
stack<int> st;
vector<vector<int>> adj(1005);
vector<vector<int>> r_adj(1005);
bool visited[1005];
void dfs(int u){
    visited[u] = 1;
    for(auto v: adj[u]){
        if(!visited[v])
            dfs(v);
    }
    st.push(u); // da duyet xong dinh u thi push vao
}
void rev_dfs(int u){
    visited[u] = 1;
    for(auto v: r_adj[u]){
        if(!visited[v])
            rev_dfs(v);
    }
}
void SCC(){
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i);
    }
    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!visited[u]){
            cnt++;
            rev_dfs(u);
        }
    }
    if(cnt == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(visited, 0, sizeof(visited));
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            r_adj[i].clear();
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            r_adj[v].push_back(u);
        }
        SCC();
    }
    return 0;
}
