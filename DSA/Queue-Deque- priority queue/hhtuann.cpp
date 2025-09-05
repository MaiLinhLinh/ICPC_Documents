#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int NMAX = 1e3 + 5;
int n, m;
string matrix[NMAX];
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
vector<vector<int>> dist(NMAX, vector<int>(NMAX, INT_MAX));
vector<vector<int>> mark(NMAX, vector<int>(NMAX, 0));
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool isValid(pii u)
{
    return u.fi > 0 && u.fi < m - 1 && u.se >= 0 && u.se <= n - 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> matrix[i];
    }

    for (int i = 1; i < m - 1; i++) {
        int w = matrix[i][0] != '#';
        pq.push({ w, { i, 0 } });
        dist[i][0] = w;
        mark[i][0] = true;
    }
    while (!pq.empty()) {
        pii u = pq.top().se;
        int currentW = pq.top().fi;
        pq.pop();
        for (int i = 0; i < 8; i++) {
            pii v = { u.fi + dx[i], u.se + dy[i] };
            if (isValid(v) && !mark[v.fi][v.se]) {
                int w = matrix[v.fi][v.se] != '#';
                dist[v.fi][v.se] = currentW + w;
                pq.push({ dist[v.fi][v.se], { v.fi, v.se } });
                mark[v.fi][v.se] = true;
            }
        }
    }

    int ans = INT_MAX;

    for (int i = 1; i < m - 1; i++)
        ans = min(ans, dist[i][n - 1]);

    cout << ans;

    return 0;
}
