#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e7 + 7)
using namespace std;
/*
G1 co do dai = F1, G2 co do dai = F2, G3 co do dai = F3...
=> k la vi tri thi di so sanh voi day fibonacci.
Gn = Gn-2 + Gn-1 hay do dai cua Gn = Fn-2 + Fn-1. neu k la vi tri > Fn-2 thi
co nghia la ki tu do nam o xau Gn-1, vi tri la k - f[n-2] cua xau Gn-1.
*/
ll f[100];
void fibo()
{
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 92; i++)
        f[i] = f[i - 2] + f[i - 1];
}
void Kitu(ll n, ll k)
{ // k la vi tri
    if (n == 1) { // G[1] = A
        cout << "A\n";
        return;
    }
    if (n == 2) { // G[2] = B
        cout << "B\n";
        return;
    }
    if (k > f[n - 2])
        Kitu(n - 1, k - f[n - 2]);
    else
        Kitu(n - 2, k);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fibo();
    int t;
    cin >> t;
    while (t--) {
        ll n;
        ll i;
        cin >> n >> i;
        Kitu(n, i);
    }
    return 0;
}
