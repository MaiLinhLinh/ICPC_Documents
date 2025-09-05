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
/*
Trong một nhà máy, có n máy đang hoạt động, máy thứ i cần đúng ai giây để làm ra được 1 sản phẩm. Bên nhà phân phối đang cần gấp m sản phẩm, nhiệm vụ của bạn là tính thời gian tối thiểu để nhà máy làm xong được m sản phẩm đó.
*/

// hàm check xem với thời gian t (s) có thể sản xuất đủ m sản phẩm không

bool can_produce(ll t, ll m, int a[], int n)
{
    ll sp = 0;
    for (int i = 0; i < n; i++) {
        sp += t / a[i];
        if (sp >= m)
            return true;
    }
    return false;
}

// ham binary search check tung thoi gian chay tu 1 den thoi gian max
ll bSearch(ll m, int a[], int n)
{
    ll l = 1;
    ll r = 1e18;
    ll ans = r;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (can_produce(mid, m, a, n)) {
            ans = mid;
            r = mid - 1; // thu voi time nho hon
        } else
            l = mid + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll m;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll result = bSearch(m, a, n);
    cout << result << '\n';

    return 0;
}
