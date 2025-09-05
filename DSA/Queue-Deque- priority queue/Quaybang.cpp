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
        vector<int> a(6), b(6);
        for (int i = 0; i < 6; i++)
            cin >> a[i];
        for (int i = 0; i < 6; i++)
            cin >> b[i];
        queue<pair<vector<int>, int>> q;
        q.push({ a, 0 });
        while (!q.empty()) {
            vector<int> cur = q.front().first; // trang thai bang hien tai dang xet
            int ans = q.front().second; // so buoc den hien tai
            q.pop();
            if (cur == b) { // neu trang thai bang hien tai = dich thi in so buoc
                cout << ans << "\n";
                break;
            }
            // xoay trai
            vector<int> tmp = cur; // trang thai bang sau khi xoay trai
            tmp[0] = cur[3];
            tmp[1] = cur[0];
            tmp[3] = cur[4];
            tmp[4] = cur[1];
            q.push({ tmp, ans + 1 });
            // xoay phai
            tmp = cur; // trang thai bang sau khi xoay phai
            tmp[1] = cur[4];
            tmp[2] = cur[1];
            tmp[4] = cur[5];
            tmp[5] = cur[2];
            q.push({ tmp, ans + 1 });
        }
    }
    return 0;
}
