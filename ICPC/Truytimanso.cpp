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
Bạn được cho trước 1 số nguyên dương n, nhiệm vụ của bạn rất đơn giản, đó chính là hãy tìm ra số x nhỏ nhất có thể sao cho tổng các số lẻ trong đoạn [1,x]lớn hơn hẳn tổng các số chẵn trong đoạn [x+1,n]
*/
bool check(ll x, ll n)
{
    ll tongLe = 0, tongChan = 0;
    ll l, r;
    if (x % 2 == 0) {
        r = x - 1;
        l = x + 2;
    } else {
        r = x;
        l = x + 1;
    }
    tongLe = (r + 1) * ((r - 1) / 2 + 1) / 2;
    if (n >= l) {
        tongChan = ((n - l) / 2 + 1) * (n + l) / 2;
    }
    return tongLe > tongChan;
}

int Bsearch(ll n)
{
    ll l = 1, r = n;
    n = n - n % 2;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid, n)) {
            ans = mid;
            r = mid - 1; // thu voi so nho hon
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
        ll n;
        cin >> n;
        if (n == 1)
            cout << "1\n";
        else
            cout << Bsearch(n) << "\n";
    }

    return 0;
}
