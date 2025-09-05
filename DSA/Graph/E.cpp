#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
#define pii pair<int, int>
#define se second
#define fi first
using namespace std;
int dx[10] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[10] = { 1, -1, 2, -2, 2, -2, 1, -1 };
// int dist[10][10]; // số bước ít nhất để đi đến vị trí i, j
int visited[10][10];
void bfs(int a, int b, int m, int n, int res)
{
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push({ res, { a, b } });
    // dist[a][b] = 0;
    visited[a][b] = 1;
    while (!pq.empty()) {
        int x = pq.top().se.fi;
        int y = pq.top().se.se;
        int ans = pq.top().fi;
        pq.pop();
        if (x == m && y == n) {
            cout << ans << "\n";
            return;
        }
        for (int i = 0; i < 8; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x > 0 && new_y > 0 && new_x <= 8 && new_y <= 8 && !visited[new_x][new_y]) {
                pq.push({ ans + 1, { new_x, new_y } });
                //  dist[new_x][new_y] = dist[x][y] + 1;
                visited[new_x][new_y] = 1;
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
        string s1, s2;
        cin >> s1 >> s2;
        int x = s1[0] - 'a' + 1;
        int y = s1[1] - '0';
        int m = s2[0] - 'a' + 1;
        int n = s2[1] - '0';
        memset(visited, 0, sizeof(visited));
        // memset(dist, 0, sizeof(dist));
        bfs(x, y, m, n, 0);
        // cout << dist[m][n] << "\n";
    }
    return 0;
}
