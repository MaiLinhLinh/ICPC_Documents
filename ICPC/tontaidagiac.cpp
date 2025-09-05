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
// tổng độ dài tất cả các cạnh còn lại > cạnh maxx
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    int maxx = 0;
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        tong += a[i];
    }
    if (tong - maxx > maxx)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
