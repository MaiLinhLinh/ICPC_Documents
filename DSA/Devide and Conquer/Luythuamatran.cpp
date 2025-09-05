#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
ll n, k;
struct Matran {
    ll x[10][10];
    friend Matran operator*(Matran a, Matran b)
    {
        Matran c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c.x[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    c.x[i][j] = (c.x[i][j] + a.x[i][k] * b.x[k][j]) % mod;
                }
            }
        }
        return c;
    }
};
Matran binpow(Matran a, ll k)
{
    if (k == 1)
        return a;
    Matran x = binpow(a, k / 2);
    if (k % 2 != 0)
        return x * x * a;
    return x * x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        Matran a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> a.x[i][j];
        }
        Matran b = binpow(a, k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << b.x[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}
