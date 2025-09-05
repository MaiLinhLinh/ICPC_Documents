#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)

ll luca[90];
void solve()
{
    luca[0] = 2;
    luca[1] = 1;
    for (int i = 2; i <= 87; i++) {
        luca[i] = luca[i - 1] + luca[i - 2];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    int n;
    cin >> n;
    cout << luca[n];

    return 0;
}
