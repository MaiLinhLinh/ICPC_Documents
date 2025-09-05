#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
vector<ll> v; // luu cac so may man
void sinh()
{
    queue<ll> q;
    q.push(6);
    q.push(8);
    while (!q.empty()) {
        ll tmp = q.front();
        v.push_back(tmp);
        q.pop();
        if (tmp * 10 + 6 <= 1e18)
            q.push(tmp * 10 + 6);
        if (tmp * 10 + 8 <= 1e18)
            q.push(tmp * 10 + 8);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sinh();
    sort(v.begin(), v.end());
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        ll l = lower_bound(v.begin(), v.end(), a) - v.begin(); // vi tri so may man dau tien >= a
        ll r = upper_bound(v.begin(), v.end(), b) - v.begin(); // vi tri so may man dau tien > b
        r--; // vi tri so may man dau tien <= b
        ans = r - l + 1;
        cout << ans << "\n";
    }
    return 0;
}
