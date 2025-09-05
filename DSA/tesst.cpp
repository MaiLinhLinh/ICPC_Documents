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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll ans = LONG_LONG_MIN;
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            while (!dq.empty() && i - dq.front() > k)
                dq.pop_front();
            ans = max(ans, 1ll * (dq.front()) + 1ll * a[i]); // tổng lớn nhất nếu nhận phần tử a[i]
            while (!dq.empty() && ans >= a[dq.back()]) // duy trì thứ tự giảm dần của maxsum
                dq.pop_back();
            dq.push_back(i);
        }
        cout << ans << "\n";
    }
    return 0;
}
