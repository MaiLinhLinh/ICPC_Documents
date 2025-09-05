#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int a[1000];
int n, m, k, ok;
void sinh()
{
    int i = n;
    while (i > 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else {
        a[i] = 1;
    }
}
bool check()
{
    int cnt0 = 0, cnt1 = 0;
    int dem1 = 0, dem0 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            cnt1++;
            if (cnt0 == k) {
                dem0++;
            } else if (cnt0 > k)
                return 0;
            cnt0 = 0;
        } else {
            cnt0++;
            if (cnt1 == m) {
                dem1++;
            } else if (cnt1 > m)
                return 0;
            cnt1 = 0;
        }
    }
    if (cnt0 == k) {
        dem0++;
    } else if (cnt0 > k)
        return 0;
    if (cnt1 == m) {
        dem1++;
    } else if (cnt1 > m)
        return 0;

    // cout << "soday1: " << dem1 << " soday0: " << dem0 << "\n";
    return (dem0 == 1 && dem1 == 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> m >> n;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    ok = 1;
    while (ok) {
        if (check()) {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
        sinh();
    }
    return 0;
}
