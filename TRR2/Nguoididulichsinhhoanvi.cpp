#include <algorithm>
#include <iostream>
#define nmax int(1e6 + 7)
using namespace std;
int a[nmax], result[nmax];
int n, check, ans = nmax;
int c[500][500];
void sinh()
{
    int i = n - 1;
    while (i > 0 && a[i] > a[i + 1])
        i--;
    if (i <= 1) {
        check = 0;
    } else {
        int j = n;
        while (j > i && a[i] > a[j])
            j--;
        swap(a[i], a[j]);
        sort(a + i + 1, a + n);
    }
}
void solve()
{
    int chiphi = 0;
    for (int i = 1; i <= n; i++)
        chiphi += c[a[i]][a[i + 1]];
    if (chiphi <= ans) {
        ans = chiphi;
        for (int i = 1; i <= n + 1; i++) {
            result[i] = a[i];
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        a[i] = i;
    a[n + 1] = 1;
    check = 1;
    while (check) {
        solve();
        sinh();
    }
    cout << ans << ".0\n";
    for (int i = 1; i <= n + 1; i++)
        cout << result[i] << " ";
}