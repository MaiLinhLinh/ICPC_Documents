#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n;
ll cnt = 0;
void Try(ll current, int x, int y)
{
    if (current > n)
        return;
    if (current > 0)
        cnt++;
    Try(current * 10 + x, x, y);
    Try(current * 10 + y, x, y);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            Try(0, i, j);
        }
        Try(i, 0, i);
    }
    for (int i = 1; i <= 9; i++) {
        ll x = i;
        while (x <= n) {
            x = x * 10 + i;
            cnt -= 8;
        }
    }
    cout << cnt << "\n";
    return 0;
}
