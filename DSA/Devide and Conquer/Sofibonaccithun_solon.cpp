#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// dinh nghia ma tran va toan tu nhan ma tran
struct Matran {
    ll x[2][2];
    friend Matran operator*(Matran a, Matran b)
    {
        Matran c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    c.x[i][j] += a.x[i][k] * b.x[k][j];
                    c.x[i][j] %= mod;
                }
            }
        }
        return c;
    }
};
Matran binpow(Matran a, ll n)
{
    if (n == 1)
        return a;
    Matran x = binpow(a, n / 2);
    if (n % 2)
        return a * x * x;
    return x * x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Matran a;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a.x[0][0] = a.x[1][0] = a.x[0][1] = 1;
        a.x[1][1] = 0;
        Matran ans = binpow(a, n);
        cout << ans.x[1][0] << "\n";
    }
    return 0;
}
