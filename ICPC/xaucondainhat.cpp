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
    int ans = 0;
    int pos0 = -1, pos1 = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            pos0 = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            pos1 = i;
            break;
        }
    }
    cout << pos1 - pos0 + 1 << "\n";
    return 0;
}
