#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
ll m, n, A[100][100], f[100][100];
void Calc()
{
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            if (i == 1 || j == 1)
                f[i][j] = 1;
            else
                f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    Calc();
    while (t--) {
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cin >> A[i][j];
        }
        cout << f[20][20] << "\n";
    }
    return 0;
}
