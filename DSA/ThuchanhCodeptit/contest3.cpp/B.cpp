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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int h[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    h[0] = 0;
    int d[n + 1] = { 0 }; // nang luong tieu hao it nhat khi nhay den i
    d[1] = 0;
    for (int i = 2; i <= n; i++)
        d[i] = 1e9;
    for (int i = 1; i <= n; i++) {
        if (i <= 2) {
            for (int j = 1; j <= i - 1; j++)
                d[i] = min(d[i], d[j] + abs(h[i] - h[j]));

        } else {
            for (int j = i - 2; j <= i - 1; j++)
                d[i] = min(d[i], d[j] + abs(h[i] - h[j]));
        }
    }
    cout << d[n] << "\n";
    return 0;
}
