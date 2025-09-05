#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int f[n + 2]; // day con tang don dieu dai nhat den phan tu A[i]
    for (int i = 1; i <= n; i++)
        f[i] = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) { // duyet cac phan tu truoc chi so i
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + 1);
                ans = max(ans, f[i]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
