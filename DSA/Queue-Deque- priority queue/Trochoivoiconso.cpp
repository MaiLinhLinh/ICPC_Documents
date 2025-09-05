#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// ý tưởng: dùng queue để lưu số hiện tại và số bước để biến đổi về số hiện tại
// nếu 1 số đã xuất hiện trong queue rồi mà sau đó nó vẫn xuất hiện thì ko thêm vào queue nữa vì số bước biến đổi nhiều hơn với số đã ở trong queue.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        queue<pair<int, int>> q;
        int n;
        cin >> n;
        map<int, int> mp;
        q.push({ n, 0 });
        while (!q.empty()) {
            pair<int, int> tmp = q.front(); // trạng thái đang xét hiện tại
            int cur = tmp.first;
            int res = tmp.second;
            q.pop();
            if (cur == 1) {
                cout << res << "\n";
                break;
            } else {
                for (int i = 2; i * i <= cur; i++) { // tìm max của tích 2 ước
                    if (cur % i == 0) {
                        int maxx = max(i, cur / i);
                        if (mp[maxx] == 0) { // nếu chưa tồn tại trong queue thì thêm vào
                            q.push({ maxx, res + 1 });
                            mp[maxx] = 1;
                        }
                    }
                }
                if (!mp[cur - 1]) { // trừ đi 1
                    q.push({ cur - 1, res + 1 });
                    mp[cur - 1] = 1;
                }
            }
        }
    }
    return 0;
}
