#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick(int _n)
        : n(_n)
        , f(n + 1, 0)
    {
    }

    // cộng val vào index i
    void update(int i, ll val)
    {
        for (; i <= n; i += i & -i)
            f[i] += val;
    }

    // lấy tổng prefix [1..i]
    ll query(int i) const
    {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }

    // lấy tổng [l..r]
    ll query(int l, int r) const
    {
        return query(r) - query(l - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    Fenwick fw(N);

    // đọc mảng và khởi tạo BIT
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        fw.update(i, a);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u;
            ll K;
            cin >> u >> K;
            fw.update(u, K);
        } else {
            int u, v;
            cin >> u >> v;
            cout << fw.query(u, v) << "\n";
        }
    }
    return 0;
}
