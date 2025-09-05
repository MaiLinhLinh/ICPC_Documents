#include <bits/stdc++.h>
using namespace std;

#define NAME "Hoang Hoang Tuan"
#define LL long long

int n, s; // so luong menh gia tien va tong so tien
int t[100]; // mang menh gia tien
int ans = INT_MAX; // ket qua la so luong to tien it nhat

void Try(int i, int remaining, int currentCount)
{
    if (remaining == 0) {
        ans = min(ans, currentCount);
        return;
    }
    if (i == n || currentCount >= ans)
        return;

    // Khong lay menh gia t[i]
    Try(i + 1, remaining, currentCount);

    // Lay menh gia t[i]
    if (remaining >= t[i]) {
        int cnt = remaining / t[i];
        Try(i + 1, remaining - cnt * t[i], currentCount + cnt);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> t[i];

    Try(0, s, 0);

    cout << ans;
    return 0;
}