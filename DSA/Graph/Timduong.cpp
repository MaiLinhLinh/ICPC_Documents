#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e5 + 7)
#define pii pair<int, int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pii>adj[10005];
    vector<int> visited(10005);
    for(int i = 1; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x,z});
    }
    // bfs
    int d[nmax] = {0};// đường di ngắn nhất từ đỉnh 1 đến đỉnh x
    queue<int> q;
    q.push(1);
    visited[1]= 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto x: adj[cur]){
            if(!visited[x.first]){
                q.push(x.first);
                d[x.first]++;
                visited[x.first] = 1;
            }
        }
    }
    return 0;
}
