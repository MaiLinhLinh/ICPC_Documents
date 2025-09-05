#include<bits/stdc++.h>
using namespace std;
bool visited[1005];
int a[105][105];
int n;
void dfs(int u){
    visited[u] = 1;
    for(int v = 1; v <= n; v++){
        if(!visited[v] && a[u][v] == 1 ){
            dfs(v);
        }
    }
}
int demtplt(){
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    int cnt = demtplt();
    //cout << cnt << "\n";
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i][j] == 1){
                a[i][j] = 0;
                a[j][i] = 0;
                int dem = demtplt();
                if(dem > cnt)
                    ans++;
                a[i][j] = a[j][i] = 1; // khoi phuc lại
            }
        }

    }
    cout << ans << "\n";

}
