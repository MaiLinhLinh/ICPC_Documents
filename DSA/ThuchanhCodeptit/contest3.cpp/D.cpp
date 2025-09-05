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
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ti = 0, teo = 0;
    int l = 1, r = n;
    while (l <= r) {
        if (a[l] >= a[r]) {
            ti += a[l];
            l++;
        } else if (l <= r && a[l] < a[r]) {
            ti += a[r];
            r--;
        }
        if (l <= r && a[l] >= a[r]) {
            teo += a[l];
            l++;
        } else if (l <= r && a[l] < a[r]) {
            teo += a[r];
            r--;
        }
    }
    cout << ti << " " << teo;
    return 0;
}
