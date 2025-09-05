#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e3 + 7)
int n;
int a[nmax][nmax];
vector<int> visited(nmax);
void dfs(int u)
{
    stack<int> st;
    st.push(u);
    cout << u << " ";
    visited[u] = true;
    while (!st.empty()) {
        u = st.top();

        st.pop();
        for (int v = 1; v <= n; v++) {
            if (a[u][v] == 1 && !visited[v]) {
                st.push(u);
                st.push(v);
                cout << v << " ";
                visited[v] = true;
                break;
            }
        }
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
    dfs(1);

    return 0;
}
