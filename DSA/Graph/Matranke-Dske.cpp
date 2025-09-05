#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v, e;
    cin >> v >> e;
    vector<int> adj[100];
    vector<int> visited(100);
    int a[v + 2][v + 2];
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (a[i][j] == 1)
                adj[i].push_back(j);
        }
    }
    for (int i = 1; i <= v; i++) {
        for (auto x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
