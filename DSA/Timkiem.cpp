#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// binary_search(a, a+ n, x);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    int k = 1;
    int a[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < a[i - 1])
            k = i;
    }
    int ans = 0;
    int p = lower_bound(a + 1, a + k, x) - a;
    int q = lower_bound(a + k, a + n + 1, x) - a;
    if (a[p] == x) {
        ans = p;
    }
    if (a[q] == x)
        ans = q;
    cout << ans - 1 << "\n";
    return 0;
}
