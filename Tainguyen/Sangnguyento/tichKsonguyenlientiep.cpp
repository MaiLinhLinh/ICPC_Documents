// Cho 2 số nguyên N
//  và K
// . Tìm số nguyên lớn nhất không vượt quá N
//  và là tích của K
//  số nguyên tố liên tiếp.
#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long
#define nmax 2100000
const unsigned long long inf = 18446744073709551615;

vector<ULL> v;
bool p[nmax];
ULL n;
int k;

void prime()
{
    p[0] = p[1] = true; // khong la ngto
    for (int i = 2; i * i < nmax; i++)
        if (!p[i])
            for (int j = i * i; j < nmax; j += i)
                p[j] = true;
    for (long long i = 2; i < nmax; i++)
        if (!p[i])
            v.push_back(i);
}
ULL check(int mid)
{
    ULL res = 1;
    for (int i = 0; i < k; i++) {
        if (res > inf / v[mid + i])
            return inf;
        res *= v[mid + i];
    }
    return res;
}
void solve()
{
    // your solution
    cin >> n >> k;
    int l = 0;
    int r = upper_bound(v.begin(), v.end(), int(pow(n, 1.0 / k))) - v.begin();
    ULL ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid) < n) {
            ans = check(mid);
            l = mid + 1;
        } else
            r = mid - 1;
    }
    if (ans == 0)
        cout << -1;
    else
        cout << ans;
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // input
    prime();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}