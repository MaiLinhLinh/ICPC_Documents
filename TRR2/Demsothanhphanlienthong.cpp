#include <iostream>
#include <vector>
using namespace std;
// #ifdef MaiLinh
// #include <debug.h>
// #else
// #define debug(...) 12
// #endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
int n, a[100][100];
vector<bool> visited(nmax);

void dfs(int u)
{
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (a[u][v] == 1 && !visited[v])
            dfs(v);
    }
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
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << '\n';

    return 0;
}
