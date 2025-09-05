#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
const int du = 32768;
int n, a, b[nmax], ans; // b[i]: luu so cach bien doi tu i ve 0
void Try(int x, int cnt) // cnt : so cach bien doi tu a sang x;
{
    if (cnt > ans)
        return;
    if (b[x]) {
        ans = min(ans, cnt + b[x]);
        return;
    }
    if (x == 0) {
        ans = min(ans, cnt);
        return;
    }
    Try((2 * x) % du, cnt + 1);
    Try((x + 1) % du, cnt + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 0) {
            cout << "0 ";
            continue;
        }
        a %= du;
        if (a == 0) {
            cout << "1 ";
            continue;
        }
        ans = 1e9;
        Try(a, 0);
        b[a] = ans;
        cout << ans << " ";
    }
    return 0;
}
