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
double tinh(pair<int, int> a, pair<int, int> b)
{
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> pii(n + 1);

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        pii[i] = { x, y };
    }
    int ans;
    for (int i = 1; i <= n; i++) {
        double max = 0;
        for (int j = 1; j <= n; j++) {
            if (j == i)
                continue;
            double tmp = tinh(pii[i], pii[j]);
            if (tmp > max) {
                max = tmp;
                ans = j;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
