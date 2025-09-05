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
        while (r <= n && tong + a[r] <= s) {
            tong += a[r];
            r++;
        }
        // sau vong while, tong hien tai <= s voi chi so cuoi = r - 1
        // tu l den r-1 co r-1 -l + 1 đoạn thoả mãn tổng <= s
        ans += r - l;
        // tru a[l] để chuẩn bị cho l tiếp theo
        tong -= a[l];
    }
    cout << ans << "\n";
    return 0;
}
