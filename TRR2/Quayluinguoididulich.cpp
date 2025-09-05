#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n;
int c[500][500];
int a[nmax];
int result[nmax];
int visited[nmax];
int ans = nmax;
int cmin = nmax;
void Try(int i, int chiphi)
{
    if (i > n) {
        ans = chiphi + c[a[n]][1];
        for (int i = 1; i <= n + 1; i++)
            result[i] = a[i];
        return;
    }
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            a[i] = j;
            visited[j] = 1;
            chiphi += c[a[i - 1]][a[i]];

            if (chiphi + cmin * (n - i + 1) <= ans)
                Try(i + 1, chiphi);

            visited[j] = 0;
            chiphi -= c[a[i - 1]][a[i]];
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
            cin >> c[i][j];
            if (c[i][j] != 0)
                cmin = min(cmin, c[i][j]);
        }
    }
    int chiphi = 0;
    a[1] = a[n + 1] = 1;
    Try(2, chiphi);
    cout << ans << ".0\n";
    for (int i = 1; i <= n + 1; i++)
        cout << result[i] << " ";

    return 0;
}
