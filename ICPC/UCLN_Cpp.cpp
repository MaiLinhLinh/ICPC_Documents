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

ll ucln(ll a, ll b)
{
    if (b == 0)
        return a;
    return ucln(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a;
        string b;
        cin >> a >> b;
        // tính b% a để ép về ll
        ll mod_a = 0;
        for (int i = 0; i < b.size(); i++)
            mod_a = (mod_a * 10 + (b[i] - '0')) % a;

        cout << ucln(a, mod_a) << "\n"; // ulcn(a, b%a);
    }

    return 0;
}
