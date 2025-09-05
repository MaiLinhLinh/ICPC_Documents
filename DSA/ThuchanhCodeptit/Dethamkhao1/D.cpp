#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
class DSU {
public:
    int n;
    vector<int> parent, num;
    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        num.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int findSet(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findSet(parent[u]);
    }
    void unionSet(int u, int v)
    {
        int a = findSet(u);
        int b = findSet(v);
        if (a == b)
            return;
        if (num[a] < num[b])
            swap(a, b);
        parent[b] = a;
        num[a] += num[b];
    }
    int getSize(int u)
    {
        return num[findSet(u)];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, m;
    cin >> N >> m;
    DSU dsu = DSU(N);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unionSet(u, v);
    }

    int ans = dsu.getSize(1);
    int tmp = 0;
    for (int i = 2; i <= N; i++) {

        if (dsu.findSet(i) == i && dsu.getSize(i) != dsu.getSize(1)) { // lưu ý trường hợp, getSize(1) = 11, mà 1 không phải đỉnh cha, lúc duyệt đến 4 là cha,
                                                                       // thì getSize(4) = 11, bị lặp => cần check getSize(i) != getSize(1) để chắc chắn rằng 1 và i không cùng 1 tplt
            tmp = max(tmp, dsu.getSize(i));
        }
    }
    cout << ans + tmp << "\n";

    return 0;
}
