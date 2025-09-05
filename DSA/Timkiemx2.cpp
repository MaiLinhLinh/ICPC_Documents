#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e5 + 7)
using namespace std;
int a[nmax];
int Bsearch(int l, int r, int x)
{
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < a[i - 1])
            k = i;
    }
    int ans = -1;
    int p = Bsearch(0, k - 1, x);
    int q = Bsearch(k, n - 1, x);
    if (p != -1)
        ans = p;
    else if (q != -1)
        ans = q;
    cout << ans << "\n";
}
