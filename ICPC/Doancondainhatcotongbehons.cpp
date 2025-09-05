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
// day con dai nhat co tong nho hon hoac bang k
// 2 con trỏ l và r đều trỏ vào phần tử đầu tiên. => tổng = phần tử đầu tiên
/*
nếu tổng <= k thì cố định l và tăng r
nếu tổng > k thì ans = max(ans,r - l), l++, tong -= a[l-1];
*/
bool check(int a[], int n, int s)
{
    for (int i = 1; i <= n; i++) {
        if (a[i] <= s)
            return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll s;
    cin >> n >> s;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int r = 1;
    ll tong = 0;
    ll ans = check(a, n, s);
    for (int l = 1; l <= n; l++) { // duyet left
        while (r <= n && tong + a[r] <= s) { // tăng right cho đến khi tổng + a[r] > s
            tong += a[r];
            r++;
        }
        // tổng <= s với chỉ số cuối là r - 1; => độ dài là r-1-l+1 = r - l
        ans = max(ans, 1ll * (r - l));
        tong -= a[l];
    }
    cout << ans << "\n";

    return 0;
}
