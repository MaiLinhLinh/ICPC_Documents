#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k;
int BSearch(int a[])
{
    int l = 1; // chieu dai thanh thep nho nhat
    int r = *max_element(a, a + n); // chieu dai thanh thep lon nhat
    int maxD = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += a[i] / mid;
        if (cnt >= k) {
            maxD = max(maxD, mid);
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return maxD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int a[n + 2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = BSearch(a);
    cout << ans << "\n";
    return 0;
}
