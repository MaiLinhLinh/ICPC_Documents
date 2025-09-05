#include <iostream>
#include <stack>
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
vector<vector<int>> b(MAXN, vector<int>(MAXN, 0));
vector<bool> visited(MAXN, false);
stack<int> st;

void firstDFS(int u)
{
    visited[u] = true;
    for (int v = 1; v <= N; ++v)
        if (a[u][v] && !visited[v])
            firstDFS(v);
    st.push(u);
}
void secondDFS(int u)
{
    visited[u] = true;
    for (int v = 1; v <= N; ++v)
        if (b[u][v] && !visited[v])
            secondDFS(v);
}
void hhtuann()
{
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
        if (!visited[i])
            firstDFS(i);

    fill(visited.begin(), visited.end(), false);

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!visited[v]) {
            secondDFS(v);
            ++cnt;
        }
    }

    if (cnt == 1)
        cout << "strongly connected" << endl;
    else
        cout << "not strongly connected" << endl;

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