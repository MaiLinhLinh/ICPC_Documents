#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e5 + 7)
using namespace std;
ll a[nmax];
ll f[nmax];
// f[r] - f[l-1] = k;
// f[l-1] = f[r] - k;
unordered_map<ll, int> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        mp.clear();
        mp[0] = 0; // luu index
        int index = 1e9;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            f[i] = f[i - 1] + a[i];
            if (!mp.count(f[i])) // f[i] co cac gia tri = nhau, chi gan index cho f[i] dau tien
                mp[f[i]] = i; // gan chi so
            if (mp.count(f[i] - k)) // f[i] = f[r]; f[i] - k = f[r] - k = f[l-1]
                index = min(index, mp[f[i] - k]);
        }
        ll sum = 0;
        if (index == 1e9)
            cout << "NOT FOUND";
        else {
            for (int i = index + 1; i <= n; i++) {
                cout << a[i] << " ";
                sum += a[i];
                if (sum == k)
                    break;
            }
        }
        cout << "\n";
    }
    return 0;
}
