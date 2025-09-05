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
// so đoạn con có không quá K phần tử khác nhau
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int r = 1;
    unordered_map<int, int> mp; // trong trường hợp ko cần thứ tự thì cứ dùng unorder_map
    ll ans = 0;
    for (int l = 1; l <= n; l++) {
        while (r <= n) {
            int x = mp.count(a[r]); // x = 0 neu map chưa có a[r], = 1 nếu đã có
            if (mp.size() + (1 - x) <= k) { // nếu chưa có, mà thêm vào map thì map.size() + 1
                if (x)
                    mp[a[r]]++;
                else
                    mp[a[r]] = 1;
                r++;
            } else
                break;
        }
        // mp.size() <= k xét đến r - 1
        // tuc là từ l đến r - 1 thoả mãn
        if (r >= l)
            ans += r - l;

        mp[a[l]]--;
        if (mp[a[l]] == 0)
            mp.erase(a[l]);
    }
    cout << ans << '\n';

    return 0;
}
