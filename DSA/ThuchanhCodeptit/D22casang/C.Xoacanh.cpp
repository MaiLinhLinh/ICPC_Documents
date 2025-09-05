#include <bits/stdc++.h>
using namespace std;
vector<int> v(100);

class DSU {
public:
    int n;
    vector<int> parent, num;
    DSU(int N)
    {
        this->n = N;
        parent.resize(N + 1);
        num.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            num[i] = 1;
        }
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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<int, int>> edges(M + 1);
    for (int i = 1; i <= M; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<pair<int, int>> queries(Q + 1);
    int deleted[M + 1] = { 0 };
    for (int i = 1; i <= Q; i++) {
        cin >> queries[i].first >> queries[i].second;
        if (deleted[queries[i].first] == 1)
            queries[i].first = -1; // bo canh nay di, (khong danh dau deleted vi khong ro rang=> nen bo canh khong can dung)
        else
            deleted[queries[i].first] = 1;
    }

    DSU dsu = DSU(N);
    for (int i = 1; i <= M; i++) {
        auto [x, y] = edges[i];
        if (deleted[i] == 0)
            dsu.unionSet(x, y);
    }
    vector<int> ans;
    for (int i = Q; i >= 1; i--) {
        auto [e, u] = queries[i];
        ans.push_back(dsu.getSize(u));

        auto [x, y] = edges[e];
        if (e != -1)
            dsu.unionSet(x, y);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << "\n";
    return 0;
}