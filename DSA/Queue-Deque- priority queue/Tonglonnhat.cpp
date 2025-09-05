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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        priority_queue<pair<ll, int>> pq; // lưu tổng lớn nhất và chỉ số đến vị trí có tổng lớn nhất đó
        pq.push({ a[0], 0 });
        // cout << pq.top().first << " " << pq.top().second << " \n";
        for (int i = 1; i < n; i++) {
            while (!pq.empty() && i - pq.top().second > k) // nếu tổng có vị trí cách i đang xét quá k đơn vị thì pop
                pq.pop();
            pair<ll, int> cur = pq.top();
            // cout << pq.top().first << " " << pq.top().second << " \n";
            ll sum = cur.first + a[i]; // cập nhật tổng mới đến vị trí a[i]
            pq.push({ sum, i });
        }
        while (!pq.empty() && pq.top().second != n - 1) // vì phải có a[0], a[n-1] nên tổng lớn nhất phải có chỉ số n-1
            pq.pop();
        cout << pq.top().first << "\n";
    }
    return 0;
}
