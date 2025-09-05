#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// y tuong sinh hoan vi tu 1 den n, hoan vi bat dau = 1.
// X[i] la thanh pho thu i
ll n, C[100][100], X[20], used[20];
ll d = 0, ans = INT_MAX, Cmin = INT_MAX;
void Try(int i)
{ // voi moi vi tri i, co the la 1 trong n thanh pho
    for (int j = 1; j <= n; j++) {
        if (used[j] == 0) {
            used[j] = 1;
            X[i] = j;
            d += C[X[i - 1]][X[i]]; // d la tong chi phi duong di. C[X[i-1]][X[i]] la chi phi duong di tu thanh pho X[i-1] den thanh pho X[i]
            if (i == n) // da di het n thanh pho
                ans = min(ans, d + C[X[n]][X[1]]); // tong chi phi duong di that su = tong chi phi duong di den n + chi phi duong di tu n ve thang 1
            else if (d + (n - i + 1) * Cmin < ans)
                Try(i + 1);
            used[j] = 0;
            d -= C[X[i - 1]][X[i]];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> C[i][j];
            if (C[i][j] != 0)
                Cmin = min(Cmin, C[i][j]);
        }
    }
    memset(used, 0, sizeof(used));
    X[1] = 1;
    used[1] = 1; // co dinh thanh pho dau tien
    Try(2);
    cout << ans << "\n";
    return 0;
}
