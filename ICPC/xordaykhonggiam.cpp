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
int MSB(int x)
{
    for (int i = 30; i >= 0; i--) {
        if ((x >> i) & 1)
            return i;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n > 60)
        cout << "1";
    else {
        map<int, int> msb;
        for (int i = 1; i <= n; i++) {
            int x = MSB(a[i]);
            msb[x]++;
        }
        for (auto k : msb) {
            if (k.second >= 3) {
                cout << "1";
                return 0;
            }
        }
        int prefixXor[100] = { 0 };
        for (int i = 1; i <= n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ a[i];
        }
        int ans = 1e9;
        for (int l = 1; l <= n; l++) {
            for (int r = l + 1; r <= n; r++) {
                for (int i = l + 1; i < r; i++) {
                    int x = prefixXor[i] ^ prefixXor[l - 1];
                    int y = prefixXor[r] ^ prefixXor[i];
                    if (x > y) {
                        ans = min(ans, r - l - 1); // số lần xor ( xor từ l đến i => 1 số, và xor từ i+1 đến r => 1 số) từ l đến r có r-l+1 số, sau khi xor còn 2 số => số lần xor là r-l-1
                    }
                }
            }
        }
        if (ans == 1e9)
            ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
