#include <algorithm>
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

int N, u;
vector<vector<int>> a(MAXN, vector<int>(MAXN, 0));
vector<bool> visited(MAXN, false);
vector<pair<int, int>> ans;

void printEulerPath(int u)
{
    stack<int> st;
    vector<int> path;

    st.push(u);
    while (!st.empty()) {
        u = st.top();
        bool check = false;

        for (int v = 1; v <= N; ++v) {
            if (a[u][v]) {
                check = true;
                a[u][v] = a[v][u] = 0;
                st.push(v);
                break;
            }
        }
        if (!check) {
            path.push_back(u);
            st.pop();
        }
    }

    for (int i = path.size() - 1; i >= 0; --i)
        cout << path[i] << " ";
    cout << endl;
}
void hhtuann()
{
    cin >> N >> u;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> a[i][j];
        }
    }

    printEulerPath(u);

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