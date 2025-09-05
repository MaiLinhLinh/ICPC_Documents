#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e5 + 7)
using namespace std;
bool f[nmax];
void sang()
{
    f[0] = f[1] = 1; // khong la so nguyen to
    for (int i = 2; i * i <= nmax; i++) {
        if (!f[i]) {
            for (int j = i * i; j <= nmax; j += i)
                f[j] = 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sang();
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        queue<pair<string, int>> q; // lưu pair gồm số hiện tại và số bước biến đổi về số hiện tại
        map<string, int> mp;
        q.push({ s, 0 });
        mp[s] = 1;
        while (!q.empty()) {
            pair<string, int> cur = q.front(); // trạng thái hiện tại đang xét
            string cur_num = cur.first; // số đang xét
            int res = cur.second;
            q.pop();
            if (cur_num == t) {
                cout << res << "\n";
                break;
            }
            for (int i = 0; i < 4; i++) { // mỗi chữ số đều thay từ 0 đến 9 rồi kiểm tra
                string new_num = cur_num;
                for (int j = 0; j < 10; j++) {
                    if (i == 0 && j == 0) // nếu vị trí đầu tiên mà j = 0 thì ko thực hiện
                        continue;
                    new_num[i] = j + '0';
                    if (!mp.count(new_num) && f[stoi(new_num)] == 0) {
                        q.push({ new_num, res + 1 });
                        mp[new_num] = 1;
                    }
                }
            }
        }
    }
    return 0;
}
