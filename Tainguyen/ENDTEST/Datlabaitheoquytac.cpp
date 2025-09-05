//
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // your solution
    int n, k;
    cin >> n >> k;
    int r = n % 2;
    n /= 2;
    if (k <= n + r)
        cout << 2 * k - 1;
    else {
        int i = 0;

        while (k > n + r) {
            i++;
            k -= n + r;
            r = n % 2;
            n /= 2;
        }
        cout << (2 * k - 1) * (1 << i);
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // input
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}