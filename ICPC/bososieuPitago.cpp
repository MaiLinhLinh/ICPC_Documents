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
    ll a;
    cin >> a;
    ll a_0 = a * a * 2;
    int ok = 0;
    for (ll b = 1; b <= 100005; b++) {
        ll b_2 = b * b;
        if (a_0 > b_2) {
            ll c_2 = a_0 - b_2;
            ll c = (ll)sqrt(c_2);
            if (c < 100001 && c * c == c_2 && a != b && a != c && c != b) {
                ok = 1;
                cout << "YES";
                break;
            }
        }
    }
    if (ok == 0)
        cout << "NO";

    return 0;
}
