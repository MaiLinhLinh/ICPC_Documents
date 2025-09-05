#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// sort theo v[i]/w[i]: luong gia tri /1kg( vi minh can luong gia tri lon nhat)
ll n, w[200], v[200];
ll Max = 0, m;
void Try(int i, ll re_weight, ll value) // i la mat hang thu i
{
    for (int j = re_weight / w[i]; j >= 0; j--) { // j la bien xet kha nang lay bao nhieu mat hang thu i
        value += j * v[i];
        re_weight -= j * w[i];
        if (i == n) { // duyet xong n mat hang
            Max = max(Max, value); // cap nhat ket qua gia tri
        } else if (value + re_weight * 1.0 * v[i + 1] / w[i + 1] > Max)
            Try(i + 1, re_weight, value);
        // backtrack
        value -= j * v[i];
        re_weight += j * w[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        Max = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (1.0 * v[i] / w[i] < 1.0 * v[j] / w[j]) {
                    swap(w[i], w[j]);
                    swap(v[i], v[j]);
                }
            }
        }
        // for (int i = 1; i <= n; i++)
        //     cout << w[i] << " ";
        // cout << "\n";
        // for (int i = 1; i <= n; i++)
        //     cout << v[i] << " ";
        // cout << "\n";
        Try(1, m, 0);
        cout << Max << "\n";
    }
    return 0;
}
