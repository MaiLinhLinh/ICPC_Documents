#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        ll n1 = stol(s1, nullptr, 2);
        ll n2 = stol(s2, nullptr, 2);
        cout << n1 * n2 << "\n";
    }
    return 0;
}
