#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// ý tưởng, tìm max của mảng tổng=> deque sẽ lưu chỉ số mà liên quan đến tổng
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
        vector<ll> maxsum(n, LONG_LONG_MIN);
        maxsum[0] = a[0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            while (!dq.empty() && i - dq.front() > k)
                dq.pop_front();
            maxsum[i] = maxsum[dq.front()] + 1ll * a[i]; // tổng lớn nhất nếu nhận phần tử a[i]
            while (!dq.empty() && maxsum[i] >= maxsum[dq.back()]) // duy trì thứ tự giảm dần của maxsum
                dq.pop_back();
            dq.push_back(i);
        }
        cout << maxsum[n - 1] << "\n";
    }
    return 0;
}
