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
int a[1005];
int BSearch(int l, int r, int x)
{
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x)
            return 1;
        else if (a[mid] > x)
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int k = 0 - (a[i] + a[j]);
                if (BSearch(j + 1, n - 1, k))
                    cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
