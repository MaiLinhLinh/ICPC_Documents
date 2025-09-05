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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        map<int, int> mp;
        for (int i = l; i <= r; i++) {
            mp[a[i]]++;
        }
        long long sum = 0;
        for (auto x : mp) {
            if (x.second % 2 == 0) {
                sum = sum ^ x.first;
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
