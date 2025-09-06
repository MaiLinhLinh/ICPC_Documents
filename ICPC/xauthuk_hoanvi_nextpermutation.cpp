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
    int k;
    cin >> k;
    sort(s.begin(), s.end());
    if (k == 1) {
        cout << s << "\n";
        return 0;
    }
    // Sinh k-1 hoán vị
    for (int i = 1; i < k; i++) {
        if (!next_permutation(s.begin(), s.end())) {
            return 0;
        }
    }
    cout << s << "\n";

    return 0;
}
