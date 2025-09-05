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
// vien keo thu i co luong duong la ai, q truy van, moi truy van tra loi cau hoi can an it nhat bao nhieu vien keo de tieu thu luong duong >= x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int query[q + 1];
        for (int i = 1; i <= q; i++)
            cin >> query[i];
        int prefixSum[n + 1] = { 0 };
        sort(a + 1, a + n + 1, greater<int>());
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + a[i];
        }

        sort(prefixSum + 1, prefixSum + n + 1);

        for (int i = 1; i <= q; i++) {
            int pos = lower_bound(prefixSum + 1, prefixSum + n + 1, query[i]) - prefixSum;
            if (pos == n + 1)
                cout << "-1 ";
            else
                cout << pos << " ";
        }
        cout << "\n";
    }
    return 0;
}
