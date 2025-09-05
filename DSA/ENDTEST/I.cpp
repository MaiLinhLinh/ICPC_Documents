#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define nmax int(1e6 + 7)
using namespace std;
int n, k;
int a[nmax];
int dem = 0;
void Try(int i, int sum)
{
    for (int j = 1; j <= k; j++) {
        a[i] = j;
        if (sum + a[i] > n)
            continue;
        else if (sum + a[i] == n) {
            dem++;
            dem %= mod;
        } else
            Try(i + 1, sum + a[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    Try(1, 0);
    cout << dem << "\n";
    return 0;
}
