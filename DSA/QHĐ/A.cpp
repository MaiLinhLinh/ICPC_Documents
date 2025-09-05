#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
ll C[1005][1005];
void nCk()
{
    for (int i = 0; i < 1005; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
    }
    for (int i = 1; i < 1005; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] % mod + C[i - 1][j] % mod) % mod;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    nCk();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << C[n][k] << "\n";
    }
    return 0;
}
