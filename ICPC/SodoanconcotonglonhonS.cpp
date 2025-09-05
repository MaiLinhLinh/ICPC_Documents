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
// So doan con co tong lon hon hoac bang S
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
    ll ans = 0;
    for (int l = 1; l <= n; l++) {
        while (r <= n && tong < s) {
            tong += a[r];
            r++;
        }
        // luc nay doan tu l -> r-1 có tổng >= s, thì đoạn từ l -> r, l -> r+1,...l -> n thoả mãn => với mỗi l, số lượng đoạn con thoả mãn là n - (r -1) + 1
        if (tong >= s)
            ans += n - r + 2;
        tong -= a[l];
    }
    cout << ans << "\n";

    return 0;
}
