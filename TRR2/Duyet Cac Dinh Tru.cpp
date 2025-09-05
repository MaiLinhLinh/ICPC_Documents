#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#ifdef HoangHoangTuan
#include <debug.h>
#else
#define debug(...) 12
#endif

#define endl '\n'
#define int long long

const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;

int N, cnt;
vector<vector<int>> a(MAXN, vector<int>(MAXN, 0));
vector<bool> visited(MAXN, false);
vector<int> ans, vertex;

vector<int> BFS(int u)
{
    vector<int> bfs;
    queue<int> q;
    visited[u] = true;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();
        bfs.push_back(u);
        for (int v = 1; v <= N; ++v) {
            if (a[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    sort(bfs.begin(), bfs.end());
    return bfs;
}
void init()
{
    fill(visited.begin(), visited.end(), false);
    vertex.clear();
    for (int v = 1; v <= N; ++v)
        vertex.push_back(v);
}
void hhtuann()
{
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> a[i][j];
        }
    }

    for (int u = 2; u <= N; ++u) {
        init();
        visited[u] = true;
        vertex.erase(vertex.begin() + u - 1);
        if (BFS(1) != vertex) {
            ans.push_back(u);
        }
    }

    for (int x : ans)
        cout << x << " ";

    return;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        hhtuann();

    return 0;
}
/* Take Off Toward Your Dream ! */