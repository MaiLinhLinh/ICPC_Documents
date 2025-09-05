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
    string s;
    cin >> s;
    int n = s.size();
    int l[n + 1];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        l[i] = 1;
        for (int j = 0; j < i; j++) {
            if (s[j] <= s[i]) {
                l[i] = max(l[i], l[j] + 1);
            }
        }
        ans = max(ans, l[i]);
    }

    cout << ans << "\n";

    return 0;
}
