#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// int p[105], q[105], f[205];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int p[m + 1], q[n + 1], f[m + n + 1];
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            cin >> q[i];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i + j] += p[i] * q[j];
            }
        }
        for (int i = 2; i <= m + n; i++) // i = 1, j = 1=> fmin = f[2]
            cout << f[i] << " ";
        cout << "\n";
    }
    return 0;
}
