#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    int a[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pq.push({ a[i], i });
    }
    int l, r = n + 1;
    for (int i = n; i >= 1; i--) {
        pair<int, int> x = pq.top();
        pq.pop();
        if (x.second != i) {
            if (r == n + 1)
                r = i;
            l = i;
        }
    }
    cout << l << " " << r;
    return 0;
}
