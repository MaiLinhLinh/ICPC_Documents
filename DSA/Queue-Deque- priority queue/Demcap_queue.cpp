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
    int n, k;
    cin >> n >> k;
    int a[n + 2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ll ans = 0;
    queue<int> q; // luu cac phan tu b truoc a[i] va thoa man a[i] - b < k. q.front la min
    for (int i = 0; i < n; i++) {
        while (!q.empty() && a[i] - q.front() >= k)
            q.pop(); // xet voi a[i] khi ma phan tu trong queue khong thoa man de bai thi pop
        ans += q.size();
        q.push(a[i]);
    }
    cout << ans << "\n";
    return 0;
}
