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
        int n, k, s;
        cin >> n >> k >> s;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        deque<int> dq;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            // nếu đầu deque không thoa mãn nằm trong đoạn từ [i-k+1, i]=> pop
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            while (!dq.empty() && a[i] <= a[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k && s > a[dq.front()])
                cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
