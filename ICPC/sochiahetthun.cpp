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
Cho trước 3 số nguyên dương a,b và n .Nhiệm vụ của bạn là hãy tìm số nguyên dương thứ n mà thoả mãn chia hết cho a hoặc b
*/
/*
 ý tưởng: Tìm trong đoạn từ 1 đến 1e18 một số x sao cho x chia hết cho a hoặc b và trước x có >= n số chia hết cho a hoặc b
*/
// hàm tính bcnn
ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}
ll countDiv(ll x, ll a, ll b, ll LCM)
{
    // l là lcm(a,b)
    return x / a + x / b - x / LCM;
}

ll Bsearch(ll a, ll b, ll n)
{
    ll LCM = lcm(a, b);
    ll l = 1, r = 1e18;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        // cout << "l: " << l << " r: " << r << " mid: " << mid << " count: " << mid / a + mid / b - mid / LCM << "\n";
        ;
        if (countDiv(mid, a, b, LCM) >= n) {
            // cout << countDiv(mid, a, b, LCM) << ", mid: " << mid << "\n";
            ans = mid;
            r = mid - 1; // thử với số nhỏ hơn
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
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        cout << Bsearch(a, b, n) << "\n";
    }

    return 0;
}
