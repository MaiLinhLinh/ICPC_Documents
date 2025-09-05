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
    set<int> adj[v + 1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i = 1; i <= v; i++)
    {
        if (adj[i].empty())
            continue;
        cout << "Dinh ke cua " << i << " : ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
