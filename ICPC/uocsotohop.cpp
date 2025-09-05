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
Với hai số tự nhiên N và K (K < N), số tổ hợp chập K của N phần tử được ký hiệu là C(K,N).
Bài toán đặt ra là hãy đếm số ước số của C(K,N).
*/
ll nCk[505][505];

void tohop()
{
    for (int j = 0; j <= 501; j++) {
        nCk[0][j] = 1;
        nCk[j][j] = 1;
    }

    for (int i = 1; i <= 501; i++) {
        for (int j = i + 1; j <= 501; j++) {
            nCk[i][j] = nCk[i - 1][j - 1] + nCk[i][j - 1];
        }
    }
}
/*
ý tưởng: tính số mũ của số nguyên tố p theo công thức Legen
với mọi số nguyên tố p <= n, số mũ của p trong n! là v(n!) = tổng [n/p^i] với i = 1 đến vô cùng
C(n, k) = n!/k!(n-k)!
=> số mũ của p là v(n!) - v(k!) - v((n-k)!)

*/
ll somu(int n, int p)
{
    ll cnt = 0;
    while (n > 0) {
        n /= p;
        cnt += n;
    }
    return cnt;
}
int snt(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    while (cin >> n >> k) {
        ll ans = 1;
        for (int i = 2; i <= n; i++) {
            if (snt(i)) {
                ll ep = somu(n, i) - somu(k, i) - somu(n - k, i);
                ans *= (ep + 1);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
