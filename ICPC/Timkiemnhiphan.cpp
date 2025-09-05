#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e5 + 7)
int a[nmax];
int pos_fi = -1, pos_se = -1;
int first_index(int l, int r, int x)
{
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            pos_fi = mid;
            // Tim ve ben trai
            r = mid - 1;
        } else if (a[mid] < x) {
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return pos_fi;
}

int final_index(int l, int r, int x)
{

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            pos_se = mid;
            // Tim kiem ben phai
            l = mid + 1;
        } else if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return pos_se;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--) {
        int t, x;
        cin >> t >> x;
        pos_fi = pos_se = -1;
        if (t == 1) {
            if (binary_search(a + 1, a + n + 1, x))
                cout << "YES\n";
            else
                cout << "-1\n";
        } else if (t == 2) {
            int ans = first_index(1, n, x);
            cout << ans << "\n";
        } else {
            int ans = final_index(1, n, x);
            cout << ans << "\n";
        }
    }
    return 0;
}
