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

bool BSearch(int l, int r, int x)
{
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid == x)
            return 1;
        else if (mid > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, s;
    cin >> k >> s;
    int cnt = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int x = s - (i + j);
            if (x > k)
                continue;
            if (BSearch(0, 2500, x))
                cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
