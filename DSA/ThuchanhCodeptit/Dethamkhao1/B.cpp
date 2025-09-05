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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int num[n + 1];
        for (int i = 0; i < n; i++)
            num[i] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (s[i] >= s[j]) {
                    num[i] = max(num[i], num[j] + 1);
                }
            }
            ans = max(ans, num[i]);
        }
        cout << ans << "\n";
    }

    return 0;
}
