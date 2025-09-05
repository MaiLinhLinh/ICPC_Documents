#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
int n;
int a[205][205];
int visited[205][205];

int valid(int x, int y)
{
    return a[x][y] == 1 && x <= n && y <= n && visited[x][y] == 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    priority_queue<pair<string, pii>, vector<pair<string, pii>>, greater<pair<string, pii>>> q;
    q.push({ "", { 1, 1 } });
    visited[1][1] = 1;
    while (!q.empty()) {
        string s = q.top().fi;
        int x = q.top().se.fi;
        int y = q.top().se.se;
        q.pop();
        if (x == n && y == n) {
            cout << s << "\n";
            return 0;
        }
        if (valid(x + 1, y)) {
            q.push({ s + 'D', { x + 1, y } });
            visited[x + 1][y] = 1;
        }
        if (valid(x, y + 1)) {
            q.push({ s + 'R', { x, y + 1 } });
            visited[x][y + 1] = 1;
        }
    }
    cout << "-1\n";
    return 0;
}
