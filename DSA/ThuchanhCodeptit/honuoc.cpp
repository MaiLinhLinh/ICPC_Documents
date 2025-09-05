#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool visited[105][105];
int a[105][105];
int cnt = 0;
int n, m;
void bfs(int u, int v){
    queue<pair<int,int>> q;
    q.push({u,v});
    cnt = 1;
    visited[u][v] = 1;
    while(!q.empty()){
        u = q.front().first;
        v = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            if( x >= 1 && x <= n && y >= 1 && y <= m && !visited[x][y] && a[x][y] == 1){
                visited[x][y] = 1;
                cnt++;
                q.push({x,y});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            a[i][j] = 0;
    }
    while(k--){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    int ans = 0;
    cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j] && a[i][j] == 1){
                bfs(i,j);
                ans = max(ans,cnt);
            }
        }
    }
    cout << ans;
    return 0;
}
