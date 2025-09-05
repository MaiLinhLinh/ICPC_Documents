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
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        deque<int> dq;
        int res[n + 1];
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0)
                dq.push_back(i);
            if (!dq.empty() && dq.front() + k <= i)
                dq.pop_front();
            if (i >= k) {
                if (dq.empty())
                    res[i] = 0;
                else
                    res[i] = a[dq.front()];
            }
        }
        for (int i = k; i <= n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }

    return 0;
}
